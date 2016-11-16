#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <stdlib.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# ifdef unix
	static char term_buffer[2048];
# else
#  define term_buffer 0
# endif

# define K_UP 4283163
# define K_DOWN 4348699
# define K_LEFT 4479771
# define K_RIGHT 4414235
# define K_ESC 27
# define K_RETURN 10
# define K_SPACE 32
# define K_DELETE 2117294875
# define K_BACKSPACE 127

enum cap {CL, US, UE, RV, MR, ME, CM, NB_CAP};

typedef struct	termios	t_termios;
typedef struct	winsize	t_winsize;

typedef struct s_entry
{
	char	*name;
	int		len;
	short	visible;
	short	selected;
}				t_entry;

typedef struct	s_term
{
	t_termios	term;
	t_termios	default_term;
	t_winsize	winsize;
	char		*name;
	char		*cap[NB_CAP];
	int			fd;
	t_entry		*entries;
	int			nb_entries;
	int			longest;
	int			hover;
}				t_term;

void	init_term(void);
t_term	*ft_term(void);
void	reset_default_term(void);
int		tputc(int i);
void	ft_tputs(char *id);
void	winsize(void);
void	refresh_screen(void);

void	init_entries(int ac, char **av);
void	print_entries(void);
void	free_entries(void);

void	ft_goto_up(void);
void	ft_goto_down(void);

int		get_key(void);

void	ft_error(char *err);

void	init_signals(void);
void	sig_win_resize(int i);
void	sig_exit(int i);
#endif
