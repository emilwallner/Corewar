/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:47:43 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/19 11:57:07 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# include "libft.h"
# include <stdarg.h>

# define TRUE 1
# define FALSE 0
# define INTEGER 0
# define DECIMAL 1
# define UDECIMAL 2
# define STRING 3
# define WSTRING 4
# define CHAR 5
# define WCHAR 6
# define PERCENT 7
# define POINTER 8
# define UUNSIGNED 9
# define UOCTAL 10
# define UHEX 11
# define HEX 12
# define OCTAL 13
# define UNSIGNED 14

typedef struct	s_vars {
	int		align;
	int		zero;
	int		plus;
	int		width;
	int		pointlen;
	int		percent;
	int		neg;
	int		f;
	int		flags;
	int		len;
	int		type;
	int		base;
	int		hash;
	char	printchar;
	char	printsign;
	int		printextra;
	int		printminus;
	int		printlen;
	int		printplus;
	int		printspace;
	int		printlastspace;
	int		printzero;
	int		printprefix;
	int		totcount;
	char	*nb;
}				t_vars;

void			ft_initialize_e(t_vars *e);
void			ft_printspace(int i, char c, t_vars *e);
void			ft_printprefix(t_vars *e);
void			nb_post_flags(t_vars *e);
void			addsign(char c, t_vars *e);
void			calc_printextra(t_vars *e);
int				ft_size_of_intmax(intmax_t nb, t_vars *e);
int				ft_size_of_uintmax(uintmax_t nb, t_vars *e);
char			*ft_atoi_uintmax(uintmax_t nb, t_vars *e);
char			*ft_atoi_intmax(intmax_t nb, t_vars *e);
int				ft_printf(char *str, ...);
char			*ft_printtype(char *str, t_vars *e);
int				ft_error_handle(t_vars *e);
void			wstrings(wchar_t *str, t_vars *e);
int				wchars_size(wchar_t c);
void			ft_printwchar(wchar_t c);
void			wchars(wchar_t c, t_vars *e);
void			percent(t_vars *e);
void			strings(char *str, t_vars *e);
void			chars(char c, t_vars *e);
void			ft_printspace(int i, char c, t_vars *e);
int				ft_putstr_count(char *str);
int				ft_putchar_count(char c);
void			ft_initialize_e(t_vars *e);
int				ft_size_of_intmax(intmax_t nb, t_vars *e);
void			u(uintmax_t nb, t_vars *e);
void			n(intmax_t nb, t_vars *e);
void			typeformat(t_vars *e);
void			ftprint(va_list ap, t_vars *e);
t_vars			ft_parser(char *str);
void			ft_printvars(t_vars *e);

#endif
