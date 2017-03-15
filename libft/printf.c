/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:45:32 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/26 10:43:07 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_flags(char *str)
{
	char	*next_type;
	char	*flags;
	int		position;
	int		first;
	int		i;

	i = -1;
	position = -1;
	first = -1;
	while (LTYPES[++i])
	{
		if ((next_type = ft_strchr(str, LTYPES[i])) && (first < 0 ||
			next_type - str < first))
			first = next_type - str + 1;
	}
	if (first == -1)
		return (NULL);
	if (!(flags = (char*)malloc(first + 1)))
		return (NULL);
	return (ft_strncpy(flags, str, first));
}

int		ft_if_flags(char *flags, t_flags *sflags)
{
	int		len;

	if (ft_strchr(flags, '*'))
		return (-1);
	ft_bzero(sflags, sizeof(t_flags));
	len = ft_strlen(flags);
	if (!len)
		return (0);
	if (len >= 1)
		ft_set_flags(sflags, flags, len);
	return (1);
}

void	ft_if_not_flags(char *str, t_flags *sflags)
{
	ft_bzero(sflags, sizeof(t_flags));
	sflags->type = '%';
	ft_set_flags(sflags, str, ft_strlen(str));
}

int		ft_init_printf(char *str, va_list ap, int *total_length)
{
	char	*flags;
	t_flags	sflags;

	while (str && *str && ft_strchr(str, '%'))
	{
		if ((str = ft_print_str(str, total_length) + 1))
		{
			if ((flags = ft_get_flags(str)))
			{
				if (ft_if_flags(flags, &sflags) == -1)
					return (-1);
				str = ft_print_params(str, &sflags, ap, total_length) - 1;
				ft_bzero(flags, ft_strlen(flags));
			}
			else if (ft_strlen(str) > 1)
			{
				ft_if_not_flags(str, &sflags);
				str = ft_print_params(str, &sflags, ap, total_length) - 1;
			}
		}
	}
	if (str)
		*total_length += ft_putstr(str);
	return (*total_length);
}

int		ft_printf(char *str, ...)
{
	va_list	ap;
	int		total_length;

	total_length = 0;
	va_start(ap, str);
	total_length = ft_init_printf(str, ap, &total_length);
	va_end(ap);
	return (total_length);
}
