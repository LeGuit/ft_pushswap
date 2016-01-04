/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstope.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:38:36 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/04 10:38:37 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_pushswap.h"

void		push(t_elem *l1, t_elem *l2)
{
	t_elem	*ptr;

	ptr = l1->top;
	l1->top = l1->top->prev;
	l1->top->next = l1->bot;
	l1->bot->prev = l1->top;
	l1->size--;//ok for a
	ptr->prev = l2->top;
	ptr->next = l2->bot;
	l2->top->next = ptr;
	l2->bot->prev = ptr;
	l2->top = ptr;
	l2->size++;
}

void		swap(t_elem *l);
{// maybe l only
	t_elem	*ptr;

	if (l->size < 2)
		return ;
	ptr = l->top;
	ptr->prev = l->top->prev->prev;
	l->top = l->top->prev;
	ptr
	l->top->next = l->bot;
	l->top->prev = tmp;
}	

	
