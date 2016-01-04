#include "ft_pushswap.h"

int				ps_lsttest(t_bords *ba, t_bords *bb)
{
	t_elem		*ptr;

	if (bb)//test if b is not null
		return (0);
	ptr = ba->bot;
	while (ptr->next->nb != ba->bot->nb)//test if a is sort
	{
		if (ptr->nb < ptr->next->nb)//transitivite
			return (0);
		ptr = ptr->next;
	}
	return (1);
}


t_bords			ps_lstinit(void)
{
	t_bords		*bords;

	if (!bords = (t_bords)malloc(sizeof(*bords)))
		ft_exit();
	bords->top = NULL;
	bords->bot = NULL;
	bords->size = 0;
	return (bords);
}

void			ps_addlast(t_bords *bords, int nb)
{
	t_elem		*new;

	if (!new = (t_elem)malloc(sizeof(*t_elem)) || !bords)
		ft_exit();
	new->nb = nb;
	if (bords->top == NULL)
	{
		bords->top = new;
		bords->bot = new;
		new->prev = new;
	}
	else
	{
		bords->top->next = new;
		new->prev = bords->top
		bords->top = new;
		bords->bot = new;
	}
	new->next = bords->bot;
	bords->size++;
}

void			ps_printlst(t_bords *bords)
