#ifndef		_FT_PUSHSWAP_H
# define 	_FT_PUSHSWAP_H

# include "includes/libft.h"

# define OPT_C				(1u << 0)
# define OPT_V				(1u << 1)

# define GET(opt, mask)		(opt & mask)
# define SET(opt, mask)		(opt |= mask)
# define UNSET(opt, mask)	(opt &= ~(mask))
# define TOGGLE(opt, mask)	(opt ^= mask)
# define PRINT(opt, mask)	ft_putchar(GET(opt, mask) ? 1 : 0)

typedef struct 				s_elem
{
	char					*next;
	char					*prev;
	int						nb;
};							t_elem;

typedef struct 				s_bords
{
	s_elem					top;
	s_elem					bot;
	int						size;
	int						opt;

};

#endif
