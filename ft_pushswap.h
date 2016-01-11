/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:21:03 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/11 18:17:08 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PUSHSWAP_H
# define _FT_PUSHSWAP_H
# include "libft/includes/libft.h"

# define OPT_C		(1u << 0)
# define OPT_V		(1u << 1)
# define OPT_ALL	(OPT_V | OPT_C)
# define C_NODE(type, ptr)	((type *)ptr)

typedef struct		s_node
{
	t_dlst			dlst;
	int				nb;
	int				color;
}					t_node;

typedef struct		s_info
{
	t_dlst			heada;
	t_dlst			headb;
	int				sizea;
	int				sizeb;
	int				opt;
	char			*stres;
}					t_info;

void				ft_exit(void);
void				ft_exit_free(t_dlst *head);
int					parse_opt(char **av, t_info *info);
void				test_arg(int ac, int index, char **av);
void				print_res(t_info *info);
void				ft_pushswap(t_info *info);
int					test_lst(t_info *info);
void				add_stres(t_info *info, char *ope);
void				algo(t_info *info);
void				unset_color(t_dlst *lsta, t_dlst *lstb);
void				rr(t_info *info);
void				rx(t_info *info, char *ope);
void				ss(t_info *info);
void				sx(t_info *info, char *ope);
void				px(t_info *info, char *ope);
#endif
