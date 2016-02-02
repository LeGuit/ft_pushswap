/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_lst_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:54:50 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/02 15:07:44 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			rrx(t_info *info, char *ope)
{
	ft_putstr(ope);
	if (!ft_strcmp(ope, "rra "))
	{
		dlst_irrotate(&info->heada);
		if (GET(info->opt, OPT_C))
		{
			unset_color(&info->heada, &info->headb);
			C_NODE(t_node, info->heada.next)->color = 4;
			C_NODE(t_node, info->heada.prev)->color = 4;
		}
	}
	else
	{
		dlst_rrotate(&info->headb);
		if (GET(info->opt, OPT_C))
		{
			unset_color(&info->heada, &info->headb);
			C_NODE(t_node, info->headb.next)->color = 4;
			C_NODE(t_node, info->headb.prev)->color = 4;
		}
	}
	info->nbope++;
}
