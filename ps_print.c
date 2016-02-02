/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 20:41:21 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/02 11:41:56 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			unset_color(t_dlst *lsta, t_dlst *lstb)
{
	t_node		*tmp;
	t_dlst		*it;

	it = lsta->next;
	while (it != lsta)
	{
		tmp = C_NODE(t_node, it);
		tmp->color = 0;
		it = it->next;
	}
	it = lstb->next;
	while (it != lstb)
	{
		tmp = C_NODE(t_node, it);
		tmp->color = 0;
		it = it->next;
	}
}

static void		print_dlst(t_dlst *list)
{
	t_node		*tmp;
	t_dlst		*it;

	it = list->next;
	while (it != list)
	{
		tmp = C_NODE(t_node, it);
		if (tmp->color != 0)
		{
			if (tmp->color == 1)
				ft_putstr(C_RED);
			if (tmp->color == 2)
				ft_putstr(C_YEL);
			if (tmp->color == 3)
				ft_putstr(C_GRE);
			ft_putnbr(tmp->nb);
			ft_putstr(C_RES);
		}
		else
			ft_putnbr(tmp->nb);
		if (it->next != list)
			ft_putchar(' ');
		it = it->next;
	}
	ft_putchar('\n');
}

void			print_res(t_info *info)
{
	if (info->nbope)
	{
		ft_putstr("\nList A : ");
		print_dlst(&info->heada);
	}
	if (!dlst_empty(&info->headb))
	{
		ft_putstr("List B : ");
		print_dlst(&info->headb);
	}
}
