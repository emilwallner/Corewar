/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 10:18:09 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/17 14:20:43 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <math.h>
# include <locale.h>
# include <wchar.h>
# include "libft.h"

# define U_MAX_BYTES 4
# define LTYPES "sSpdDioOuUxXcC%"
# define ABS(value)  (value > 0 ? value : -value)

# define HH 1
# define H 2
# define L 3
# define LL 4
# define J 5
# define Z 6

# define S_CHAR 1
# define SHORT_I 2
# define LONG_I 3
# define LONG_LONG_I 4
# define INTMAX_T 5
# define SIZE_T 6

# define U_INT 10
# define U_CHAR 11
# define U_SHORT_I 12
# define U_LONG_I 13
# define U_LONG_LONG_I 14
# define U_INTMAX_T 15

# define DOUBLE 20
# define INT 21
# define WINT_T 22
# define CHAR_PTR 23
# define WCHAR_T_PTR 24
# define VOID_PTR 25

typedef struct	s_arg {
	char	*suffix;
	char	*prefix;
	char	*param;
}				t_arg;

typedef struct	s_flags {
	int		hashtag;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		width;
	int		precision;
	int		percent;
	int		is_invalid;
	int		dot;
	int		ic;
	int		fc;
	char	type;
	int		emptyc;
	char	*flags;
	int		flags_len;
}				t_flags;

int				ft_printf(char *str, ...);
char			*ft_print_params(char *str, t_flags *sflags, va_list ap,
				int *tl);
char			*ft_print_str(char *str, int *tl);
char			*ft_conv_num(char *param, t_flags *sflags);
void			ft_if_pluspace(t_arg *arg, t_flags *f);
void			ft_if_width(t_arg *arg, t_flags *f);
void			ft_if_precision(t_arg *arg, t_flags *f);
void			ft_special_flags(char *str, t_flags *sflags);
int				ft_set_flags(t_flags *sflags, char *flags, int len);
char			*ft_get_flags(char *str);
char			*ft_uitoa_b(unsigned int value, int base);
char			*ft_ulitoa_b(uintmax_t value, int base);
char			*ft_man_width(char *param, t_flags *sflags);
char			*ft_man_precision(char *param, t_flags *sflags);
char			*ft_man_minus(char *param);
char			*ft_cast_arg(t_flags *flags, va_list ap, int *tl);
char			*ft_ctoa(int c);
wchar_t			*ft_wctoa(wchar_t c);
char			*ft_conv_alpha(char *param, t_flags *sflags);
wchar_t			*ft_conv_walpha(wchar_t *param, t_flags *sflags);
char			*ft_cast_type2(t_flags *f, va_list ap, int *tl);
char			*ft_cast_type(t_flags *f, va_list ap, int base, int *tl);
size_t			ft_wstrlen(const wchar_t *ws);
size_t			ft_wbyteslen(const wchar_t *ws);
size_t			ft_wputstr(const wchar_t *s);
int				ft_wputchar(wchar_t c);
wchar_t			*ft_wstrncpy(wchar_t *dest, const wchar_t *src, size_t n);
char			*ft_wgetchar(wchar_t c);
wchar_t			*ft_wstrncpyp(wchar_t *dest, const wchar_t *src, size_t n);
int				ft_get_nb_wchar(wchar_t *src, int n);
int				ft_get_nb_bytes(wchar_t *src, int n);
char			*ft_toupperstr(char *str);
char			*ft_strjoin_free(char *s1, char *s2, int to_free);
char			*ft_strsub_free(char *s, unsigned int start, size_t len);
#endif
