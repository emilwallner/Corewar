/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:08:13 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/24 15:11:41 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_reverse(t_list **begin_list)
{
	t_list *begin;
	t_list *middle;
	t_list *last;

	if (*begin_list)
	{
		begin = *begin_list;
		middle = begin->next;
		begin->next = NULL;
		while (middle)
		{
			last = middle->next;
			middle->next = begin;
			begin = middle;
			middle = last;
		}
	}
}
