/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 20:46:15 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/02 12:14:33 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			ft_exit(int nb)
{
	if (nb == 1)
		ft_putendl_fd("ft_pushswap: No arguments", 2);
	else if (nb == 2)
	{
		ft_putendl_fd("ft_pushswap: illegal option", 2);
		ft_putendl_fd("usage: [-vcn] [ints no duplicates ...]", 2);
	}
	else
		ft_putstr_fd("Error\n", 2);
	exit(0);
}

void			ft_exit_free(t_dlst *head)
{
	t_node		*clear;

	while (!dlst_empty(head))
	{
		clear = (t_node *)head->next;
		dlst_del_entry(head->next);
		free(clear);
	}
	ft_exit(0);
}
