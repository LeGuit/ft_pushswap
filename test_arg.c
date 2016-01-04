/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:36:44 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/04 15:50:31 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static int		test_int(char *arg)
{

}

static int		test_dupli(int index, int ac, char **av)
{

}

static int		test_is_num()
{
}

void			test_arg(int ac, int index, char **av)
{
	while (index < ac)
	{
		if (!test_is_num(av[index]))
			ft_exit();
		if (!test_int(av[index]))
			ft_exit();
		if (!test_dupli(index, ac, av))
			ft_exit();
	}
}
