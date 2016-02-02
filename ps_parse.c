/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:17:46 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/02 12:41:57 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void		get_opt(char *av, t_info *info)
{
	size_t		i;

	i = 1;
	while (i < ft_strlen(&av[0]))
	{
		if (av[i] == 'c')
			SET(info->opt, OPT_C);
		else if (av[i] == 'v')
			SET(info->opt, OPT_V);
		else if (av[i] == 'n')
			SET(info->opt, OPT_N);
		else
			ft_exit(2);
		i++;
	}
}

int				parse_opt(char **av, t_info *info)
{
	size_t		i;

	if (av[1][0] != '-')
		return (0);
	i = 1;
	while (i < ft_strlen(av[1]))
	{
		if (!ft_isdigit(av[1][i]))
			break ;
		i++;
	}
	if (i == ft_strlen(av[1]))
		return (0);
	get_opt(av[1], info);
	return (1);
}
