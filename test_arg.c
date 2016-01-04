/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:36:44 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/04 18:49:45 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static int		test_int(char *arg)
{
	long long	llarg;

	llarg = ft_atoll(arg);
	if (llarg > 2147483647 || llarg < -2147483648)
		return (0);
	return (1);
}

static int		test_dupli(int index, int ac, char **av)
{
	int			dupli;

	dupli = ft_atoi(av[index]);
	index++;
	while (index < ac)
	{
		if (ft_atoi(av[index]) == dupli)
			return (0);
	}
	return (1);
}

static int		test_is_num(char *arg)
{
	int			i;

	i = 0;
	if (!ft_strchr("-+0123456789", arg[i]))
		return (0);
	if (arg[i] == '-' || arg[i] == '+')
		i = 1;
	while (arg[i])
	{
		ft_putchar(arg[i]);
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

void			test_arg(int ac, int index, char **av)
{
	while (index < ac)
	{
		if (!test_is_num(av[index]))
			ft_exit();
		ft_putendl("YOU");
		if (!test_int(av[index]))
			ft_exit();
		if (!test_dupli(index, ac, av))
			ft_exit();
	}
	return ;
}
