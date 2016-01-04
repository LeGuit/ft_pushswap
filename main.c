/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:16:20 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/04 20:23:15 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			ft_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void			ft_exit_free(t_dlst *head)
{
	t_node		*clear;

	while (!dlst_empty(head))
	{
		clear = (t_node *)head->next;
		dlst_del_entry(head->next);
		free(clear);
	}
	ft_exit();
}

static void		init_head(t_info *info)
{
	dlst_init(&info->heada);
	dlst_init(&info->headb);
	UNSET(info->opt, OPT_ALL);
}

int				main(int ac, char **av)
{
	t_info		info;
	t_node		*tmp;
	int			i;

	if (ac < 2)
		ft_exit();
	init_head(&info);
	i = parse_opt(av, &info) + 1;
	test_arg(ac, i, av);
	while (i < ac)
	{
		if (!(tmp = (t_node *)malloc(sizeof(t_node))))
			ft_exit_free(&info.heada);
		tmp->nb = ft_atoi(av[i]);
		dlst_add_tail(&tmp->dlst, &info.heada);
		i++;
	}
	print_res(&info);
//	print_dlst(&info);
//	ft_pushswap(&info);
	return (0);
}
