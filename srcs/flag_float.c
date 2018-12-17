/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:24:01 by alan              #+#    #+#             */
/*   Updated: 2018/12/15 23:37:17 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

typedef union	u_double
{
	double		d;
	long		l;
}				t_double;

static double	get_nb(char length, va_list valist)
{
	double	nb;

	nb = 0;
	if (length == 0)
		nb = va_arg(valist, double);
	else if (length == 'l')
		nb = va_arg(valist, double);
	else if (length == 'L')
		nb = va_arg(valist, long double);
	return (nb);
}

char			*flag_float(t_format *fmt, va_list valist)
{
	double	nb;
	char	*str;

	nb = get_nb(fmt->length, valist);
	str = ft_ftoa(nb, fmt->precision);

	fmt->width = ft_strlen(str);
	return (str);
}
