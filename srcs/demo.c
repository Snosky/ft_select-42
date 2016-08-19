#include <ft_select.h>

static void	init_term(void)
{
	char	*termtype;
	int	success;
	char	termbuffer[2048];

	if ((termtype = getenv("TERM")) == 0)
	{
		ft_putendl_fd("Specify a terminal type with \
			'setenv TERM <yourtype>'.", 2);
		exit(EXIT_FAILURE);
	}

	success = tgetent(termbuffer, termtype);
	if (success < 0)
	{
		ft_putendl_fd("Could not access the termcap data base.", 2);
		exit(EXIT_FAILURE);
	}
	if (success == 0)
	{
		ft_putendl_fd("Terminal type is not defined", 2);
		exit(EXIT_FAILURE);
	}
}

static int voir_touche(void)
{
	char	buffer[3];
	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
			ft_putchar(buffer[1]);
		else if (buffer[0] == 4)
		{
			ft_putendl("\nLeave"); 
			return (0);
		}
	}
	return (0);
}

int	ft_outc(int c)
{
	ft_putchar(c);
	return (1);
}

int	main(void)
{
	struct termios	term;
	struct termios	term2;

	init_term();
	tcgetattr(0, &term);
		term2 = term;
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;

	if (tcsetattr(0, TCSADRAIN, &term) == -1)
	{
		ft_putendl_fd("Erreur main", 2);
		exit(EXIT_FAILURE);
	}

	char	*res;
	if ((res = tgetstr("cl", NULL)) == NULL)
		return (-1);
	tputs(res, 0, ft_outc);
	voir_touche();
	tcsetattr(0, 0, &term2);
	
	return (0);
}
