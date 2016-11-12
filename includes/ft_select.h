#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <stdlib.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>

# ifdef unix
	static char term_buffer[2048];
# else
#  define term_buffer 0
# endif

typedef struct	termios	t_termios;
typedef struct	winsize	t_winsize;

typedef struct	s_term
{
	t_termios	term;
	t_termios	default_term;
	t_winsize	winsize;
	char		*name;
}				t_term;

#endif
