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

void	init_term(void);
t_term	*ft_term(void);
void	reset_default_term(void);
int		tputc(int i);
void	ft_tputs(char *id);
void	winsize(void);
void	refresh_screen(void);

void	ft_error(char *err);

void	init_signals(void);
void	sig_win_resize(int i);
void	sig_exit(int i);
#endif
