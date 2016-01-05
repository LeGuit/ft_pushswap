/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 20:48:34 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/05 13:01:42 by gwoodwar         ###   ########.fr       */
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
	while (it != &info->heada)
	{
		cur = C_NODE(t_node, it);
		nex = C_NODE(t_node, it->next);
		ft_putnbr(cur->nb);
		ft_putchar('>');
		ft_putnbr(nex->nb);
		ft_putchar('\n');
		if (cur->nb > nex->nb && cnt > (info->size / 2))
			return (1);
		else if (cur->nb > nex->nb)
			return (2);
		it = it->next;
		cnt++;
	}
	return (0);
}

void			ft_pushswap(t_info *info)
{
	if (test_lst(info) == 0)
		print_res(info);
//	if (test_lst(info) == 1)
//		algorot(&info);
//	else
//		algopush(&info);
//	ft_pushswap(&info);
}
