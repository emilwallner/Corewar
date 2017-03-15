/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:07:30 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/22 16:18:07 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	if ((new_list = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (!content)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
		new_list->next = NULL;
	}
	else
	{
		if (!(new_list->content = malloc(sizeof(void const*) * content_size)))
			return (NULL);
		ft_memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
		new_list->next = NULL;
	}
	return (new_list);
}
