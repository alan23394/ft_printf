/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 23:37:04 by alan              #+#    #+#             */
/*   Updated: 2018/12/17 06:46:17 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef union	u_double
{
	double		d;
	long		l;
}				t_double;

/*
** This function takes a string that has malloced space that is guaranteed to
** fit the size of the number, and it converts the number to a string while
** placing it inside the string. It's like itoa, except for it doesn't make
** memory.
**
** The string starts at the end of the number, with the pointer pointing to the
** last digit.
**
** It will recursively break down the number, moving the string backwards with
** each step. Once the number is small enough, it will add the ascii at the
** character position. It does not care about the sign of the number.
*/

static void		ft_nbrcpy_p(long nb, int precision, char *str)
{
	if (precision > 1)
	{
		if (nb >= 10 || nb <= -10)
			ft_nbrcpy_p(nb / 10, precision - 1, str - 1);
		else
			ft_nbrcpy_p(0, precision - 1, str - 1);
	}
	if (nb < 0)
		*str = (ft_abs(nb % 10) + '0');
	else
		*str = (nb % 10 + '0');
}

static char		*fill_string(long intpart, long fraction, int precision)
{
	char	*str;
	int		len_of_intpart;
	
	len_of_intpart = ft_numlen(intpart);

	str = ft_strnew(len_of_intpart + 1 + precision);

	ft_nbrcpy_p(intpart, len_of_intpart, str + len_of_intpart - 1);
	ft_memcpy(str + len_of_intpart, ".", 1);
	ft_nbrcpy_p(fraction, precision, str + len_of_intpart + precision); 

	return (str);
}

static long		get_fraction(int exp, long mantissa, int precision)
{
	int			index;
	int			max;
	double		multiple;
	double		fraction;

	// maybe subtract precision in this equation by some expression with
	// exponent, if it's negative. after a certain amount I won't be affecting
	// many numbers at all, and this would allow for very small exponents
	multiple = (double)ft_pow(10, precision);
	// index is the bit we're looking at, starting at zero
	index = 1;
	// add to index the negative offset from exponent, to get aligned with the
	// front of the mantissa
	if (exp < 0)
		index += -(exp);
	// Max index is ((precision * 3) + (precision / 3))
	// if the number is not a multiple of 3, add 1
	// 3 adds 1, 4 adds 2
	// 9 adds 3, 10 adds 4
	//
	// 1, 1
	// 2, 1
	// 3, 1
	// 4, 2
	// 5, 2
	// 6, 2
	// 7, 3
	// 8, 3
	// 9, 3
	// 10,4
	//
	// ceil(precision / 3)
	// adding one to precision to get better rounding behavior
	max = ((precision + 1) * 3) + ft_ceil((double)((precision + 1) / 3));
	fraction = 0;
	// If there's no intpart (exp < 0) and the fractional part is not just zero
	// (by the fact that the mantissa exists), then add the implied 1 into the
	// fractional part
	// using index - 1 because index is already set to be one after where the
	// implied 1 would exist
	if (exp < 0 && mantissa)
		fraction += multiple / (1L << (index - 1));
	// max is the number of times starting at 1,
	// index is the number of times starting at 1,
	// index should go up to and including max
	while (index <= max)
	{
		// to isolate the bit, we take 52 (highest bit in mantissa part), minus
		// exponent (to offset the intpart of the binary stuff), minus index
		// (to scooch down the mantissa)
		if (mantissa & (1L << ((52 - exp) - index)))
			// index + 1 because we're starting at 1/2, and index of 0 means
			// there's an initial bit
			fraction += multiple / (1L << index);
		++index;
	}

	return(ft_round(fraction));
}

static char		*make_string(int exp, long mantissa, int precision)
{
	long	intpart;
	long	fraction;
	char	*str;

	intpart = 0;
	if (exp > 0)
	{
		intpart = (mantissa >> (52 - exp));
		if (intpart)
			intpart |= 1 << (exp);
	}

	fraction = get_fraction(exp, mantissa, precision);

	str = fill_string(intpart, fraction, precision);
	return (str);
}

char			*ft_ftoa(double nb, int precision)
{
	t_double	unb;
	int			sign;
	int			exp;
	long		mantissa;
	char		*str;

	unb.d = nb;

	// and selects only the first bit for the sign
	sign = (unb.l & 0x8000000000000000);
	// shift by 52 to isolate the exponent, and to isolate exponent, minus bias
	exp = ((unb.l >> 52) & 0x7ff) - 1023;
	// and to isolate mantissa
	mantissa = (unb.l & 0x000fffffffffffff);

	if (precision == -1)
		precision = 6;

	(void)sign;
	str = make_string(exp, mantissa, precision);

	return (str);
}