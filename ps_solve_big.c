/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:58:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/02 19:29:55 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#define G_NODE(type, get) C_NODE(type, info->get)->nb

static void		rot_in_a(t_info *info, int count)
{
	while (G_NODE(t_node, heada.next) != info->mina)
	{
		if (count < (info->sizea / 2))
			rx(info, "ra ");
		else
			rrx(info, "rra ");
		if (GET(info->opt, OPT_V))
			print_res(info);
	}
}

static void		get_min(t_info *info)
{
	t_node		*tmp;
	int			count;
	t_dlst		*it;

	it = info->heada.next;
	info->mina = C_NODE(t_node, it)->nb;
	while (it != &info->heada)
	{
		tmp = C_NODE(t_node, it);
		info->mina = MIN(info->mina, tmp->nb);
		it = it->next;
	}
	count = 0;
	it = info->heada.next;
	while (it != &info->heada)
	{
		tmp = C_NODE(t_node, it);
		if (info->mina == tmp->nb)
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
		px(info, "pb ");
		if (GET(info->opt, OPT_V))
			print_res(info);
	}
	while (!dlst_empty(&info->headb))
	{
		px(info, "pa ");
		if (GET(info->opt, OPT_V))
			print_res(info);
	}
}
/*
static void		rot_in_b(t_info *info)
{
	if (info->sizeb < 2)
		return ;
	if (G_NODE(t_node, headb.prev) == info->minb)
	{
			rrx(info, "rrb ");
			if (GET(info->opt, OPT_V))
				print_res(info);
	}
	while (G_NODE(t_node, heada.next) < G_NODE(t_node, headb.next)
			|| G_NODE(t_node, heada.next) > G_NODE(t_node, headb.prev))
	{
		rrx(info, "rrb ");
		if (GET(info->opt, OPT_V))
			print_res(info);
		if (G_NODE(t_node, headb.prev) == info->minb)
			break ;
	}
}

static void		get_min(t_dlst *head, int min, int count)
{
	t_node		*tmp;
	t_dlst		*it;

	it = head.next;
	min = C_NODE(t_node, it)->nb;
	while (it != head)
	{
		tmp = C_NODE(t_node, it);
		min = MIN(min, tmp->nb);
		it = it->next;
	}
	it = head.next;
	count = 0;
	while (it != head)
	{
		tmp = C_NODE(t_node, it);
		if (min == tmp->nb)
			break ;
		count++;
		it = it->next;
	}
}

static void		rot_in_lsts(t_info *info)
{
	int			count;

	count = (info->counta < info->countb ? info->
	while (G_NODE(t_node, heada.next) != info->mina)
	{
		if (count < (info->sizea / 2))
			rx(info, "ra ");
		else
			rrx(info, "rra ");
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
		px(info, "pb ");
		info->sizea--;
		info->sizeb++;
		if (GET(info->opt, OPT_V))
			print_res(info);
		if (G_NODE(t_node, heada.next) > G_NODE(t_node, headb.prev))
			break ;
		if(dlst_empty(&info->heada))
			return ;
	}
}
*/

/*
void			algo_big(t_info *info)
{
	while (!dlst_empty(&info->heada))
	{
		get_min(info);
		if (dlst_empty(&info->headb))
		{
			info->minb = info->min;
			push_in_b(info);
			continue ;
		}
		rot_in_b(info);
		push_in_b(info);
	}
	while (G_NODE(t_node, headb.prev) != info->minb)
	{
		rrx(info, "rrb ");
		if (GET(info->opt, OPT_V))
			print_res(info);
	}
	while (!dlst_empty(&info->headb))
	{
		px(info, "pa ");
		if (GET(info->opt, OPT_V))
			print_res(info);
	}
}*/
