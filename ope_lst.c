/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:39:46 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/02 11:37:36 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			rr(t_info *info)
{
	dlst_rotate(&info->heada);
	dlst_rotate(&info->headb);
	ft_putstr("rr ");
	if (GET(info->opt, OPT_C))
	{
		unset_color(&info->heada, &info->headb);
		C_NODE(t_node, info->heada.next)->color = 3;
		C_NODE(t_node, info->heada.prev)->color = 3;
		C_NODE(t_node, info->headb.next)->color = 3;
		C_NODE(t_node, info->headb.next)->color = 3;
	}
	info->nbope++;
}

void			rx(t_info *info, char *ope)
{
	ft_putstr(ope);
	if (!ft_strcmp(ope, "ra "))
	{
		dlst_rotate(&info->heada);
		if (GET(info->opt, OPT_C))
		{
			unset_color(&info->heada, &info->headb);
			C_NODE(t_node, info->heada.next)->color = 3;
			C_NODE(t_node, info->heada.prev)->color = 3;
		}
	}
	else
	{
		dlst_rotate(&info->headb);
		if (GET(info->opt, OPT_C))
		{
			unset_color(&info->heada, &info->headb);
			C_NODE(t_node, info->headb.next)->color = 3;
			C_NODE(t_node, info->headb.prev)->color = 3;
		}
	}
	info->nbope++;
}

void			ss(t_info *info)
{
	dlst_swap(&info->heada);
	dlst_swap(&info->headb);
	ft_putstr("ss ");
	if (GET(info->opt, OPT_C))
	{
		unset_color(&info->heada, &info->headb);
		C_NODE(t_node, info->heada.next)->color = 2;
		C_NODE(t_node, info->heada.next->next)->color = 2;
		C_NODE(t_node, info->headb.next)->color = 2;
		C_NODE(t_node, info->headb.next->next)->color = 2;
	}
	info->nbope++;
}

void			sx(t_info *info, char *ope)
{
	ft_putstr(ope);
	if (!ft_strcmp(ope, "sa "))
	{
		dlst_swap(&info->heada);
		if (GET(info->opt, OPT_C))
		{
			unset_color(&info->heada, &info->headb);
			C_NODE(t_node, info->heada.next)->color = 2;
			C_NODE(t_node, info->heada.next->next)->color = 2;
		}
	}
	else
	{
		dlst_swap(&info->headb);
		if (GET(info->opt, OPT_C))
		{
			unset_color(&info->heada, &info->headb);
			C_NODE(t_node, info->headb.next)->color = 2;
			C_NODE(t_node, info->headb.next->next)->color = 2;
		}
	}
	info->nbope++;
}

void			px(t_info *info, char *ope)
{
	ft_putstr(ope);
	if (!ft_strcmp(ope, "pa "))
	{
		dlst_move_head(info->headb.next, &info->heada);
		if (GET(info->opt, OPT_C))
		{
			unset_color(&info->heada, &info->headb);
			C_NODE(t_node, info->heada.next)->color = 1;
		}
	}
	else
	{
		dlst_move_head(info->heada.next, &info->headb);
		if (GET(info->opt, OPT_C))
		{
			unset_color(&info->heada, &info->headb);
			C_NODE(t_node, info->headb.next)->color = 1;
		}
	}
	info->nbope++;
}
