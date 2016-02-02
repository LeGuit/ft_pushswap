/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 20:48:34 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/02 13:47:57 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int				test_lst(t_info *info)
{
	t_dlst		*it;
	t_node		*cur;
	t_node		*nex;
	int			cnt;

	it = info->heada.next;
	cnt = 0;
	while (it->next != &info->heada)
	{
		cur = C_NODE(t_node, it);
		nex = C_NODE(t_node, it->next);
		if (cur->nb > nex->nb)
			return (1);
		it = it->next;
		cnt++;
	}
	return (0);
}

void			ft_pushswap(t_info *info)
{
	if (test_lst(info) == 0)
	{
		ft_printf("List already sorted!\n");
		return ;
	}
	algo(info);
	if (GET(info->opt, OPT_V))
		print_res(info);
	if (GET(info->opt, OPT_N))
		ft_printf("\nNumber of operations: %lld", info->nbope);
	if (!GET(info->opt, OPT_V) || GET(info->opt, OPT_N))
		ft_putchar('\n');
}

void			ft_pushswap_big(t_info *info)
{
	t_dlst		*it;
	int			min;
	t_node		*tmp;

	while (!dlst_empty(&info->heada))
	{
		min = -2147483648;
		it = info->heada.next;
		while (it != &info->heada)
		{
			tmp = C_NODE(t_node, it);
			min = MIN(min, tmp->nb);
			it = it->next;
		}
		it = info->heada.next;
		while (C_NODE(t_node, it)->nb != min)
		{
		   rx(info, "ra ");
		   it = it->next;
		}
		px(info, "pb ");	
	}
	print_res(info);
}
