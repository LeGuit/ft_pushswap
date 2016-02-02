/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:16:20 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/02 15:47:42 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void		init_head(t_info *info)
{
	dlst_init(&info->heada);
	dlst_init(&info->headb);
	UNSET(info->opt, OPT_ALL);
	info->sizeb = 0;
	unset_color(&info->heada, &info->headb);
	info->nbope = 0;
}

int				main(int ac, char **av)
{
	t_info		info;
	t_node		*tmp;
	int			i;

	if (ac < 2)
		ft_exit(1);
	init_head(&info);
	i = parse_opt(av, &info) + 1;
	info.sizea = ac - i;
	test_arg(ac, i, av);
	while (i < ac)
	{
		if (!(tmp = (t_node *)malloc(sizeof(t_node))))
			ft_exit_free(&info.heada);
		tmp->nb = ft_atoi(av[i]);
		dlst_add_tail(&tmp->dlst, &info.heada);
		i++;
	}
	if (ac < 15)
		ft_pushswap(&info);
	else
		ft_pushswap_big(&info);
	return (0);
}
