/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 10:24:33 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/07 12:05:03 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#define G_NODE(type, get) C_NODE(type, info->get)->nb

void			add_stres(char *stres, char *ope)
{
	char		*tmp;

	tmp = stres;
	if (!(stres = ft_strnew(ft_strlen(stres) + ft_strlen(ope) + 1)))
		ft_exit();
	ft_strcpy(stres, tmp);
	ft_strcat(stres, ope);
	free(tmp);
}

static void		test_rot(t_info *info, t_node *cura, t_node *curb, char *stres)
{
	if (info->sizeb >= 2)
	{
		if (cura->nb > G_NODE(t_node, heada.prev)
				&& curb->nb > G_NODE(t_node, headb.prev))
		{
			dlst_rotate(&info->heada);
			dlst_rotate(&info->headb);
			add_stres(stres, "rr ");
		}
	}
	if (cura->nb > G_NODE(t_node, heada.prev)
			|| curb->nb > G_NODE(t_node, headb.prev))
	{
		if (cura->nb > G_NODE(t_node, heada.prev))
		{
			ft_putstr("brot\n");
		print_res(info);
			dlst_rotate(&info->heada);
			ft_putstr("arot\n");
		print_res(info);
			add_stres(stres, "ra ");
		}
		if (info->sizeb >= 2)
		{
			dlst_rotate(&info->headb);
			add_stres(stres, "rb ");
		}
	}
	return ;
}

static void		test_swap(t_info *info, t_node *cura, t_node *curb, char *stres)
{
	if (info->sizeb >= 2)
	{
		if (cura->nb > G_NODE(t_node, heada.next->next)
				&& curb->nb > G_NODE(t_node, headb.next->next))
		{
			dlst_swap(&info->heada);
			dlst_swap(&info->headb);
			add_stres(stres, "ss ");
		}
	}
	if (cura->nb > G_NODE(t_node, heada.next->next)
			|| curb->nb > G_NODE(t_node, headb.next->next))
	{
		if (cura->nb > G_NODE(t_node, heada.next->next))
		{
			dlst_swap(&info->heada);
			add_stres(stres, "sa ");
		}
		if (info->sizeb >= 2)
		{
			dlst_swap(&info->headb);
			add_stres(stres, "sb ");
		}
	}
	return ;
}

void			algo(t_info *info, char *stres)
{
	t_node		*cura;
	t_node		*curb;
	int			sizeb;

	sizeb = 0;
	cura = C_NODE(t_node, info->heada.next);
	curb = C_NODE(t_node, info->headb.next);
	ft_putstr("inalgo\n");
	while (test_lst(info) != 0)
	{
		print_res(info);
		test_rot(info, cura, curb, stres);
		print_res(info);
		test_swap(info, cura, curb, stres);
		print_res(info);
		ft_putstr("test");
		dlst_move_head(&info->heada, &info->headb);
		add_stres(stres, "pb ");
		sizeb++;
	}
	while (dlst_empty(&info->headb))
	{
		dlst_move_head(&info->headb, &info->heada);
		add_stres(stres, "pa ");
	}
}
