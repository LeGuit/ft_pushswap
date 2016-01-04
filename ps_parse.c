/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:17:46 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/04 18:43:16 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int			parse_opt(char **av, t_info *info)
{
	size_t	i;

	if (av[1][0] != '-')
		return (0);
	i = 1;
	while (i < ft_strlen(av[1]))
	{
		if (av[1][i] == 'c')
			SET(info->opt, OPT_C);
		else if (av[1][i] == 'v')
			SET(info->opt, OPT_V);
		else
			ft_exit();
		i++;
	}
	return (1);
}
