/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/27 18:20:34 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vm.h"

void	ft_or(t_env *e, t_cursor *cursor)
{
	(void)e;
	(void)cursor;
	ft_update_cursor(e, cursor, 1);
}

void	ft_xor(t_env *e, t_cursor *cursor)
{
	(void)e;
	(void)cursor;
	ft_update_cursor(e, cursor, 1);
}

void	ft_sti(t_env *e, t_cursor *cursor)
{
	(void)e;
	(void)cursor;
	ft_update_cursor(e, cursor, 1);
}

void	ft_lldi(t_env *e, t_cursor *cursor)
{
	(void)e;
	(void)cursor;
	ft_update_cursor(e, cursor, 1);
}
