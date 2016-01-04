/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 20:46:15 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/04 20:46:49 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			ft_exit(void)
{
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
	ft_exit();
}
