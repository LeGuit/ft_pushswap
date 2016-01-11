/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:39:46 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/11 19:14:23 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			rr(t_info *info)
{
	dlst_rotate(&info->heada);
	dlst_rotate(&info->headb);
	add_stres(info, " rr");
	if (GET(info->opt, OPT_C))
	{
		unset_color(&info->heada, &info->headb);
		C_NODE(t_node, info->heada.next)->color = 3;
		C_NODE(t_node, info->heada.prev)->color = 3;
		C_NODE(t_node, info->headb.next)->color = 3;
		C_NODE(t_node, info->headb.next)->color = 3;
	}
}

void			rx(t_info *info, char *ope)
{
	add_stres(info, ope);
	if (!ft_strcmp(ope, " ra"))
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
}

void			ss(t_info *info)
{
	dlst_swap(&info->heada);
	dlst_swap(&info->headb);
	add_stres(info, " ss");
	if (GET(info->opt, OPT_C))
	{
		unset_color(&info->heada, &info->headb);
		C_NODE(t_node, info->heada.next)->color = 2;
		C_NODE(t_node, info->heada.next->next)->color = 2;
		C_NODE(t_node, info->headb.next)->color = 2;
		C_NODE(t_node, info->headb.next->next)->color = 2;
	}
}

void			sx(t_info *info, char *ope)
{
	add_stres(info, ope);
	if (!ft_strcmp(ope, " sa"))
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
}

void			px(t_info *info, char *ope)
{
	add_stres(info, ope);
	if (!ft_strcmp(ope, " pa"))
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
}
