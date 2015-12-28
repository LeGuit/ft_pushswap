// dont need to have all in both list check if only top && bot is ok

void		pa(t_elem *la, t_elem *lb)
//maybe l1 l2 cause pa & pb is the same with swap lb la
// also change ptr from bot of the 2 stack
	t_elem	*ptr;

	ptr = la->topa;
	la->topa = la->topa->prev;
	la->topa->next = la->bota;
	lb->topb->next = ptr;
	lb->topb = tmp;
	lb->topb->next = lb->botb;
	la->size--;
	lb->size++;

void		sa(t_elem *la);
// maybe l only
	t_elem	*ptr;

	ptr = la->topa;
	ptr->prev = la->topa->prev->prev;
	la->topa = la->topa->prev;
	ptr
	la->topa->next = la->bota;
	la->topa->prev = tmp;
	

	
