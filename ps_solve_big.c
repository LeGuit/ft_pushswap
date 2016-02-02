/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:58:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/02 16:48:43 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#define G_NODE(type, get) C_NODE(type, info->get)->nb

static void		rot_in_b(t_info *info)
{
	//	ft_putstr("YO");
	//	ft_printf("Heada: %d\nHeadb: %d\nTailb: %d\n", G_NODE(t_node, heada.next), G_NODE(t_node, headb.next), G_NODE(t_node, headb.prev));
//		ft_exit(1);
	if (info->sizeb < 2)
		return ;
	while (G_NODE(t_node, heada.next) < G_NODE(t_node, headb.next))
	{
		ft_putstr("BITCH");
		rrx(info, "rrb ");
		if (GET(info->opt, OPT_V))
			print_res(info);
	}
}

static void		push_in_b(t_info *info)
{
	while (dlst_empty(&info->headb) || info->sizeb < 2)
	{
		px(info, "pb ");
		info->sizea--;
		info->sizeb++;
		if (GET(info->opt, OPT_V))
			print_res(info);
	}
	while (G_NODE(t_node, heada.next) > G_NODE(t_node, headb.next))
	{
		if (G_NODE(t_node, heada.next) > G_NODE(t_node, headb.prev))
			break ;
		px(info, "pb ");
		info->sizea--;
		info->sizeb++;
		if (GET(info->opt, OPT_V))
			print_res(info);
		if(dlst_empty(&info->heada))
			return ;
	}
}

static void		rot_in_a(t_info *info, int count)
{
	while (G_NODE(t_node, heada.next) != info->min)
	{
		if (count < info->sizea / 2)
			rx(info, "ra ");
		else
			rrx(info, "rra ");
		if (GET(info->opt, OPT_V))
			print_res(info);
	}
}

static void		get_min(t_info *info)
{
	t_dlst		*it;
	t_node		*tmp;
	int			count;

	it = info->heada.next;
	info->min = C_NODE(t_node, it)->nb;
	while (it != &info->heada)
	{
		tmp = C_NODE(t_node, it);
		info->min = MIN(info->min, tmp->nb);
		it = it->next;
	}
	count = 0;
	it = info->heada.next;
	while (it != &info->heada)
	{
		tmp = C_NODE(t_node, it);
		if (info->min == tmp->nb)
			break ;
		count++;
		it = it->next;
	}
	rot_in_a(info, count);
}

void			algo_big(t_info *info)
{
	while (!dlst_empty(&info->heada))
	{
		get_min(info);
		if (dlst_empty(&info->headb))
		{
			push_in_b(info);
			continue ;
		}
		rot_in_b(info);
		push_in_b(info);
	}
	while (!dlst_empty(&info->headb))
	{
		px(info, "pa ");
		if (GET(info->opt, OPT_V))
			print_res(info);
	}
}