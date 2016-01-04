/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:16:20 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/04 15:58:57 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			ft_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit();
}

void			ft_exit_free(t_dlst *heada)
{
	t_pslst		*clear;

	while (!dlst_empty(head))
	{
		clear = head->next;
		dlst_del_entry(head->next);
		free(clear);
	}
	ft_exit();
}

int				main(int ac, char **av)
{
	t_dlst		*heada;
	t_dlst		*headb;
	t_pslst		*tmp;
	int			i;
	int			opt;

	i = parse_opt(av, &opt) + 1;
	test_arg(ac, i, av);
	dlst_init(heada);
	dlst_init(headb);
	while (i < ac)
	{
		if (!tmp = (t_pslst *)malloc(sizeof(t_pslst)))
			ft_exit_free(heada);
		tmp->nb = ft_atoi(av[i]);
		dlst_add_tail(tmp, heada);
		i++;
	}
	ft_pushswap(heada, headb, opt);
	return (0);
}
