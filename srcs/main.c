#include <ft_select.h>

#include <stdio.h>

int tputc(int c)
{
	return ((int)write(1, &c, 1));
}

t_term	*ft_term(void)
{
	static t_term	term;

	return (&term);
}

void	sig_win_resize(int i)
{
	t_term	*term;

	(void)i;
	term = ft_term();
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, (char *)&term->winsize) < 0)
			printf("Error 4\n"); // TODO : Error
}

void	sig_exit(int i)
{
	t_term	*term;
	
	term = ft_term();
	(void)i;

	tputs(tgetstr("te", NULL), 0, tputc);
	tcsetattr(0, TCSADRAIN, &(term->default_term));
	exit(EXIT_SUCCESS);
}

int main	(int ac, char **av)
{
	t_term	*term = ft_term();
	int		success;

	// On recup les informations obligatoire du terminal
	term->name = getenv("TERM");
	if (term->name == NULL)
		term->name = "DEFAULT_TERM"; //TODO : A voir si bien DEFAULT_TERM
	
	success = tgetent(term_buffer, term->name);
	if (success < 0)
		return (printf("Error 1\n")); // TODO : Gestion erreur, "Could not access the termcap data base."
	else if (success == 0)
		return (printf("Error 2\n")); // TODO : Error : "Terminal type $termtype is not defined."

	
	
	
	if (tcgetattr(0, &(term->term)) == -1 || tcgetattr(0, &(term->default_term)))
		return (printf("Error 3\n"));

	term->term.c_lflag &= ~(ICANON | ECHO);
	term->term.c_cc[VMIN] = 1;
	term->term.c_cc[VTIME] = 0;

	tcsetattr(0, TCSADRAIN, &(term->term));
	
	// On passe en mode pleine ecran
	tputs(tgetstr("ti", NULL), 0, tputc);
	//On cache le cursor
	tputs(tgetstr("vi", NULL), 0, tputc);

	sig_win_resize(0); // Call car initialization
	signal(SIGWINCH, sig_win_resize);
	signal(SIGINT, sig_exit); // Signal Ctrl-C
	
	char key[3];

	while (1)
	{
		// On clear le terminal
		tputs(tgetstr("cl", NULL), 0, tputc);

		//Window resize : TODO lib ncurses ?!

		//Test center
		char *middle = "Hello World\n";
		int left_col = (term->winsize.ws_col / 2) - (ft_strlen(middle) / 2);
		for (int s = 0; s < left_col; s++)
			tputs(" ", 0, tputc);
		tputs(tgetstr("mr", NULL), 0, tputc); // Active reverse video
		tputs(tgetstr("us", NULL), 0, tputc); // Active underline
		tputs(middle, 0, tputc);
		tputs(tgetstr("me", NULL), 0, tputc); // Remove all text style (ue for only underline);
		//End test
	
		for (int k = 0; k < ac; k++)
			tputs(av[k], 0, tputc); tputs("\n", 0, tputc);

		// Arrow test
		if (ft_strcmp(key, tgetstr("kl", NULL)) == 0)
			tputs("Left Arrow\n", 0, tputc);
		else if (ft_strcmp(key, tgetstr("ku", NULL)) == 0)
			tputs("Up Arrow\n", 0, tputc);
		else if (ft_strcmp(key, tgetstr("kd", NULL)) == 0)
			tputs("Down Arrow\n", 0, tputc);
		else if (ft_strcmp(key, tgetstr("kr", NULL)) == 0)
			tputs("Right Arrow\n", 0, tputc);
		// End test
		
		ft_bzero(key, 3);
		read(0, key, 3);
	}



	// Ferme le plein ecran
	tcsetattr(0, TCSADRAIN, &(term->default_term));
	tputs(tgetstr("te", NULL), 0, tputc);

	return (1);
}
