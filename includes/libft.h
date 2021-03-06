/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:56:25 by abarnett          #+#    #+#             */
/*   Updated: 2019/01/05 21:49:34 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define INTMAX 2147483647
# define INTMIN -2147483648

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef union		u_double
{
	double			d;
	long			l;
}					t_double;

typedef	struct		s_fp
{
	long			integral;
	long			fraction;
	int				len_i;
	int				trail_zeros;
	int				lead_zeros;
	int				len_f;
}					t_fp;

# define SIG_F (f.lead_zeros + f.len_f)
# define SIG_I (f.len_i + f.trail_zeros)

/*
** Section One
*/

void				*ft_memset(void *b, int c, size_t len);
void				*ft_nmemset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
size_t				ft_wstrlen(const wchar_t *str);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,\
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isspace(int c);
int					ft_atoi(char *str);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_strupper(char *str);

/*
** Section Two
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
char				*ft_strinit(size_t size, int c);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char*s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
int					ft_count_words(const char *str, char del);
size_t				ft_dstrlen(const char *str, char del);
char				**ft_strsplit(const char *s, char c);
size_t				ft_numlen_sign(long long num);
size_t				ft_numlen(long long num);
size_t				ft_unumlen(unsigned long long num);
size_t				ft_numlen_sign_base(long long num, int base);
size_t				ft_numlen_base(long long num, int base);
size_t				ft_unumlen_base(unsigned long long num, int base);
void				ft_strapp(char *dst, char c);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
char				*ft_ftoa(double nb, int precision);
char				*ft_ftosn(double nb, int precision);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Math
*/

int					ft_vamax(int params, ...);
int					ft_vamin(int params, ...);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
long				ft_abs(long nb);
long				ft_pow(int a, int b);
double				ft_pow_d(double a, int b);
int					ft_floor(double roundee);
int					ft_ceil(double roundee);
long				ft_round(double roundee);

/*
** Unicode
*/

char				*conv_utf8_str(wchar_t *wstr);
char				*conv_utf8_char(wchar_t wchar, char *str);

/*
** Bonus
*/

t_list				*ft_lstinit(void const *content, size_t content_size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *init);
void				ft_lstadd_tail(t_list **alst, t_list *init);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstputstr(t_list *item);
void				ft_lstputstr_len(t_list *item);
void				ft_lstmemdel(void *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstlen(t_list *head);

#endif
