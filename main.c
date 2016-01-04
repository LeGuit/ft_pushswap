/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:16:20 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/04 15:17:11 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int				main(int ac, char **av)
{
	t_dlst		*heada;
	t_dlst		*headb;
	t_pslst		*tmp;
	int			i;
	int			opt;

	test_arg(ac. av);
	dlst_init(heada);
	dlst_init(headb);
	i = parse_opt(av, &opt);
	while (i < ac)
	{
		if (!tmp = (t_pslst *)malloc(sizeof(t_pslst)))
			ft_exit_free(heada, headb);
		tmp->nb = ft_atoi(av[i]);
		dlst_add_tail(tmp, heada);
		i++;
	}
	ft_pushswap(heada, headb, opt);
	return (0);
}
