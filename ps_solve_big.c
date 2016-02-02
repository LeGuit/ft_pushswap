/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:58:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/02 15:11:00 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#define G_NODE(type, get) C_NODE(type, info->get)->nb

static void		push_in_b(t_info *info)
{
	if (dlst_empty(&info->headb) || (G_NODE(t_node, heada.next) < G_NODE(t_node, headb.next)
			&& G_NODE(t_node, heada.next) > G_NODE(t_node, headb.prev)))
		px(info, "pb ");
		ft_printf("Heada: %d\nHeadb: %d\n", G_NODE(t_node, heada.next), G_NODE(t_node, headb.next));
	if (GET(info->opt, OPT_V))
		print_res(info);
	while (G_NODE(t_node, heada.next) > G_NODE(t_node, headb.next)
			&& G_NODE(t_node, heada.next) > G_NODE(t_node, headb.prev))
	{
		ft_printf("Heada: %d\nHeadb: %d\n", G_NODE(t_node, heada.next), G_NODE(t_node, headb.next));
		px(info, "pb ");
		if (GET(info->opt, OPT_V))
			print_res(info);
		if(dlst_empty(&info->heada))
			return ;
	}
}

static void		get_min(t_info *info)
{
	t_dlst		*it;
	t_node		*tmp;

	while (!dlst_empty(&info->heada))
	{
		it = info->heada.next;
		info->min = C_NODE(t_node, it)->nb;
		while (it != &info->heada)
		{
			tmp = C_NODE(t_node, it);
			info->min = MIN(info->min, tmp->nb);
			it = it->next;
		}
		while (G_NODE(t_node, heada.next) != info->min)
		{
			rx(info, "ra ");
			if (GET(info->opt, OPT_V))
				print_res(info);
			it = it->next;
		}
		push_in_b(info);
	}
}

static void		algo_big(t_info *info)
{
	get_min(info);
	while (!dlst_empty(&info->headb))
		px(info, "pa ");
}

void			ft_pushswap_big(t_info *info)
{
	if (test_lst(info) == 0)
	{
		ft_printf("List already sorted!\n");
		return ;
	}
	algo_big(info);
	if (GET(info->opt, OPT_V))
		print_res(info);
	if (GET(info->opt, OPT_N))
		ft_printf("\nNumber of operations: %lld", info->nbope);
	if (!GET(info->opt, OPT_V) || GET(info->opt, OPT_N))
		ft_putchar('\n');
}
