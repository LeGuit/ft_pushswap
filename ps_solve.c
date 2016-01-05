/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 20:48:34 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/05 12:01:39 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static int		test_lst(t_dlst *la, t_dlst *lb)
{
	t_node		*nb1;
	t_node		*nb2;
	t_dlst		*it;

	if (!dlst_empty(lb))
		return (0);
	it = la->next;
	while (it != la)
	{
		nb1 = C_NODE(t_node, it);
		nb2 = C_NODE(t_node, it->next);
		if (nb1 > nb2)
			return (0);
		it = it->next;
	}
	return (1);
}

void			ft_pushswap(t_info *info)
{
	if (test_lst(&info->heada, &info->headb))
		print_res(info);
		//print_solution(&info);
}
