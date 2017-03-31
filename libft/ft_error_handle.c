/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 21:01:49 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/19 10:52:39 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include <stdlib.h>

int		ft_error_handle(t_vars *e)
{
	if (e->type == -1)
		return (TRUE);
	if (e->type >= 3 && e->type <= 6 && e->zero)
		return (TRUE);
	if (e->type == POINTER && e->flags > 0)
		return (TRUE);
	if (e->type == POINTER && e->pointlen != -1)
		return (TRUE);
	return (FALSE);
}
