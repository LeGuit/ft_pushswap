void		algo2(t_info *info, char *stres)
{//if lstb have 2 elems
	t_node	*cura;
	t_node	*curb;
	int	sizeb;

	sizeb = 0;
	cura = C_NODE(t_info, info->heada->next);
	curb = C_NODE(t_info, info->headb->next);
	while (test_lst(&info->heada) != 0)
	{
		if (cura->nb > cura->next->nb && curb->nb > curb->next->nb)
			ope_ss(&info->heada, &info->headb, stres);//test isempty in ope_ss || ope_rr
		else if (cura->nb > cura->next->nb || curb->nb > curb->next->nb)
			ope_sx(cura->nb > cura->next->nb ? &info->heada : &info->headb, stres);
		if (curb->nb > curb->prev->prev->nb && curb->nb > curb->prev->prev->nb)
			ope_rr(&info->heada, &info->headb, stres);
		else if (cura->nb > cura->prev->prev->nb || curb->nb > curb->prev->prev->nb)
			ope_rx(cura->nb > cura->prev->prev->nb ? &info->heada : &info->headb, stres);
		else
		{
			dslt_push(&info->heada, &info->headb);
			add_stres(stres, "pa");
			sizeb++;
		}
	}
}
