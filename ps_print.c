/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 20:41:21 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/11 14:09:14 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void		print_dlst(t_dlst *list)
{
	t_node		*tmp;
	t_dlst		*it;

	it = list->next;
	while (it != list)
	{
		tmp = C_NODE(t_node, it);
		ft_putnbr(tmp->nb);
		if (it->next != list)
			ft_putchar(' ');
		it = it->next;
	}
	ft_putchar('\n');
}

void			print_res(t_info *info)
{
	ft_putstr("List A : ");
	print_dlst(&info->heada);
	if (!dlst_empty(&info->headb))
	{
		ft_putstr("List B : ");
		print_dlst(&info->headb);
	}
	if (*(info->stres) != '\0')
		ft_putendl(info->stres + 1);
}
