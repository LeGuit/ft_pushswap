/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 10:24:33 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/11 14:06:42 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#define G_NODE(type, get) C_NODE(type, info->get)->nb

void			add_stres(t_info *info, char *ope)
{
	char		*tmp;

	tmp = info->stres;
	if (!(info->stres = ft_strnew(ft_strlen(info->stres)
					+ ft_strlen(ope) + 1)))
		ft_exit();
	ft_strcpy(info->stres, tmp);
	ft_strcat(info->stres, ope);
	free(tmp);
}

static int		test_rot(t_info *info, t_node *cura, t_node *curb)
{
	if (cura->nb > G_NODE(t_node, heada.prev)
			&& curb->nb < G_NODE(t_node, headb.prev)
			&& info->sizeb >= 2)
	{
		dlst_rotate(&info->heada);
		dlst_rotate(&info->headb);
		add_stres(info, " rr");
		return (1);
	}
	if (cura->nb > G_NODE(t_node, heada.prev)
			|| curb->nb < G_NODE(t_node, headb.prev))
	{
		if (cura->nb > G_NODE(t_node, heada.prev))
		{
			dlst_rotate(&info->heada);
			add_stres(info, " ra");
			return (1);
		}
		if (curb->nb < G_NODE(t_node, headb.next->next) && info->sizeb >= 2)
		{
			dlst_rotate(&info->headb);
			add_stres(info, " rb");
			return (1);
		}
	}
	return (0);
}

static int		test_swap(t_info *info, t_node *cura, t_node *curb)
{
	if (cura->nb > G_NODE(t_node, heada.next->next)
			&& curb->nb < G_NODE(t_node, headb.next->next)
			&& info->sizeb >= 2)
	{
		dlst_swap(&info->heada);
		dlst_swap(&info->headb);
		add_stres(info, " ss");
		return (1);
	}
	if (cura->nb > G_NODE(t_node, heada.next->next)
			|| curb->nb < G_NODE(t_node, headb.next->next))
	{
		if (cura->nb > G_NODE(t_node, heada.next->next))
		{
			dlst_swap(&info->heada);
			add_stres(info, " sa");
			return (1);
		}
		if (curb->nb < G_NODE(t_node, headb.next->next) && info->sizeb >= 2)
		{
			dlst_swap(&info->headb);
			add_stres(info, " sb");
			return (1);
		}
	}
	return (0);
}

void			algo(t_info *info)
{
	t_node		*cura;
	t_node		*curb;

	while (test_lst(info))
	{
		if (GET(info->opt,OPT_V))
			print_res(info);
		cura = C_NODE(t_node, info->heada.next);
		curb = C_NODE(t_node, info->headb.next);
		print_res(info);
		if (test_rot(info, cura, curb))
			continue ;
		if (test_swap(info, cura, curb))
			continue ;
		dlst_move_head(info->heada.next, &info->headb);
		info->sizeb++;
	}
	print_res(info);
	while (!dlst_empty(&info->headb))
	{
		dlst_move_head(info->headb.next, &info->heada);
		add_stres(info, " pa");
		info->sizeb--;
	}
	print_res(info);
	if (test_lst(info))
		algo(info);
}
