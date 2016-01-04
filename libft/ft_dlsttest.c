/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlsttest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:36:32 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/04 13:43:15 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			dlst_empty(t_dlst *head)
{
	return (head->next == head);
}

int			dlst_is_last(t_dlst *dlst, t_dlst *head)
{
	return (dlst->next == head);
}
