/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:21:03 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/04 15:21:05 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		_FT_PUSHSWAP_H
# define 	_FT_PUSHSWAP_H

# include "libft/includes/libft.h"

# define OPT_C				(1u << 0)
# define OPT_V				(1u << 1)
# define OPT_ALL			(1u << 2 - 1)

typedef struct 				s_pslst
{
	t_dlst					dlst;
	int						nb;

}							t_pslst;

#endif
