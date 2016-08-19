#ifndef FT_SELECT_H
# define FT_SELECT_H

#include <libft.h>
#include <termios.h>
#include <term.h>

typedef struct	s_elem
{
	char		*content;
	struct s_elem	*prev;
	struct s_elem	*next;
}		t_elem;

#endif
