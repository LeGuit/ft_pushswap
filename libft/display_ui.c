/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 18:11:30 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/29 13:21:24 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static size_t	display_prefix(t_mod *m, char *buf)
{
	if (GET(m->flag, F_PTR) || (ft_strchr("xX", m->convers) && *buf != '0'))
	{
		if (GET(m->flag, F_HASH) && m->convers == 'x')
			ft_strcpy(m->prefix, "0x");
		if (GET(m->flag, F_HASH) && m->convers == 'X')
			ft_strcpy(m->prefix, "0X");
		if (GET(m->flag, F_HASH) && ft_strchr("xX", m->convers) && m->length)
			m->length = ((m->length < 2) ? 2 : m->length - 2);
		if (GET(m->flag, F_PTR) && GET(m->flag, F_PREC) && m->prec == 0)
			m->length = 0;
	}
	if (GET(m->flag, F_PLUS) && ft_strchr("diD", m->convers))
		ft_strcpy(m->prefix, "+");
	if (GET(m->flag, F_NEG) && ft_strchr("diD", m->convers))
		ft_strcpy(m->prefix, "-");
	if (GET(m->flag, F_SPACE) && ft_strchr("diD", m->convers))
		ft_strcpy(m->prefix, " ");
	if (GET(m->flag, F_HASH) && m->convers == 'o' && m->prec <= ft_strlen(buf))
		SET(m->flag, F_HO);
	if (GET(m->flag, F_SPACE) && GET(m->flag, F_SPACE))
		m->length--;
	if (GET(m->flag, F_PREC) && m->prec == 0 && *buf == '0')
		*buf = '\0';
	return (ft_strlen(m->prefix));
}

static size_t	display_zero(t_mod *m, char *buf)
{
	int			i;

	i = 0;
	if (GET(m->flag, F_HO) && *buf != '0')
		m->prec = ft_strlen(buf) + 1;
	while (i < (int)(m->prec - ft_strlen(buf)))
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}

size_t			display_space(t_mod *m, char *buf)
{
	size_t		i;
	size_t		nospace;

	i = 0;
	if (ft_strchr("sS", m->convers) && GET(m->flag, F_PREC))
		nospace = (m->prec < ft_strlen(buf) ? m->prec : ft_strlen(buf));
	else
		nospace = ((m->prec) ? MAX(m->prec, ft_strlen(buf)) : ft_strlen(buf));
	if (ft_strchr("c", m->convers) && !*buf)
		nospace = 1;
	if (GET(m->flag, F_HO))
		nospace = ft_strlen(buf) + 1;
	while ((int)i < (m->length - (int)nospace))
	{
		if (GET(m->flag, F_ZERO))
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	return (i);
}

size_t			display_ui(t_mod *m, char *buf)
{
	size_t		cnt;

	cnt = 0;
	cnt += display_prefix(m, buf);
	if (GET(m->flag, F_ZERO))
		ft_putstr(m->prefix);
	if (!GET(m->flag, F_MINUS))
		cnt += display_space(m, buf);
	if (!GET(m->flag, F_ZERO))
		ft_putstr(m->prefix);
	cnt += display_zero(m, buf);
	ft_putstr(buf);
	cnt += ft_strlen(buf);
	if (GET(m->flag, F_MINUS))
		cnt += display_space(m, buf);
	return (cnt);
}

int				print_modulo(t_mod *m, va_list ap)
{
	size_t		cnt;

	(void)ap;
	cnt = 1;
	if (GET(m->flag, F_MINUS))
		ft_putchar('%');
	if (GET(m->flag, F_PREC))
	{
		while ((int)cnt < m->length)
		{
			if (GET(m->flag, F_ZERO))
				ft_putchar('0');
			else
				ft_putchar(' ');
			cnt++;
		}
	}
	if (!GET(m->flag, F_MINUS))
		ft_putchar('%');
	return (cnt);
}
