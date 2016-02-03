/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:58:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/03 11:06:43 by gwoodwar         ###   ########.fr       */
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
