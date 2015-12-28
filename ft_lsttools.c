#include "ft_pushswap.h"

t_bords			ps_lstinit(void)
{
	t_bords		*bords;

	if (!bords = (t_bords)malloc(sizeof(*bords)))
		ft_exit();
	bords->topa = NULL;
	bords->bota = NULL;
	bords->topb = NULL;
	bords->botb = NULL;
	bords->sizea = 0;
	bords->sizeb = 0;
	return (bords);
}

void			ps_addlast(t_bords *bords, int nb)
{
	t_elem		*new;

	if (!new = (t_elem)malloc(sizeof(*t_elem)) || !bords)
		ft_exit();
	new->nb = nb;
	if (bords->topa == NULL)
	{
		bords->topa = new;
		bords->bota = new;
		new->prev = new;
	}
	else
	{
		bords->topa->next = new;
		new->prev = bords->topa
		bords->topa = new;
		bords->bota = new;
	}
	new->next = bords->bota;
	bords->sizea++;
}

void			ps_printlst(t_bords *bords)