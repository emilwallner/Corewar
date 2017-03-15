/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_rand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:54:13 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/19 17:23:10 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		buffer_to_stock(int fd, char **stock, int *bytes_read)
{
	char	*buffer;
	char	*tmp;

	buffer = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (buffer == NULL)
		return (0);
	*bytes_read = read(fd, buffer, BUFF_SIZE);
	if (*bytes_read == -1)
	{
		free(buffer);
		return (0);
	}
	buffer[*bytes_read] = '\0';
	tmp = ft_strjoin(*stock, buffer);
	free(*stock);
	*stock = tmp;
	free(buffer);
	return (1);
}

void	cut_stock(char **stock, char *str)
{
	char		*tmp;

	tmp = ft_strdup(str + 1);
	ft_strdel(stock);
	*stock = tmp;
}

int		file_end(char **line, char **stock)
{
	if (ft_strlen(*stock))
	{
		*line = ft_strdup(*stock);
		ft_strdel(stock);
		return (1);
	}
	return (0);
}

int		error_handling(char **stock)
{
	if (stock)
		ft_strdel(stock);
	return (-1);
}

int		gnl_rand(const int fd, char **line, int ctrl)
{
	static char		*stock = NULL;
	char			*str;
	int				bytes_read;

	if (fd < 0 || !(line) || BUFF_SIZE < 0)
		return (-1);
	if (!(stock))
		stock = ft_strnew(0);
	while (!(ft_strchr(stock, '\n')))
	{
		if ((int)ft_strlen(stock) > ctrl && !ft_strchr(stock, '\n') &&
		!ft_strchr(str, '\n'))
			return (-1);
		if (!(buffer_to_stock(fd, &stock, &bytes_read)))
			return (error_handling(&stock));
		if (bytes_read == 0)
			return (file_end(line, &stock));
	}
	str = ft_strchr(stock, '\n');
	*line = ft_strsub(stock, 0, str - stock);
	cut_stock(&stock, str);
	return (1);
}
