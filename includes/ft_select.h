#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <stdlib.h>
# include <termios.h>
# include <term.h>

# ifdef unix
	static char term_buffer[2048];
# else
#  define term_buffer 0
# endif



#endif
