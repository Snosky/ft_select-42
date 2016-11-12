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

int main	(int ac, char **av)
{
		(void)ac;
		(void)av;
	t_term	*term = ft_term();
	int		success;

	//struct termios	default_term;
	//struct termios	term;

	// On recup les informations obligatoire du terminal
	term->name = getenv("TERM");
	if (term->name == NULL)
		term->name = "DEFAULT_TERM"; //TODO : A voir si bien DEFAULT_TERM
	
	success = tgetent(term_buffer, term->name);
	if (success < 0)
		return (printf("Error 1\n")); // TODO : Gestion erreur, "Could not access the termcap data base."
	else if (success == 0)
		return (printf("Error 2\n")); // TODO : Error : "Terminal type $termtype is not defined."

	
	// On passe en mode pleine ecran
	tputs(tgetstr("ti", NULL), 0, tputc);
	
	
	if (tcgetattr(0, &(term->term)) == -1 || tcgetattr(0, &(term->default_term)))
		return (printf("Error 3\n"));

	term->term.c_lflag &= ~(ICANON | ECHO);
	term->term.c_cc[VMIN] = 1;
	term->term.c_cc[VTIME] = 0;

	tcsetattr(0, TCSADRAIN, &(term->term));

	// Active arrow key
	tputs(tgetstr("ks", NULL), 0, tputc);
//	tputs(tgetstr("ku", NULL), 0, tputc);

	char key[3];

	sig_win_resize(0); // Call car initialization
	while (1)
	{
		// On clear le terminal
		tputs(tgetstr("cl", NULL), 0, tputc);

		//Window resize : TODO lib ncurses ?!
		signal(SIGWINCH, sig_win_resize);

		//Test center
		char *middle = "Hello World";
		int left_col = (term->winsize.ws_col / 2) - (ft_strlen(middle) / 2);
		for (int s = 0; s < left_col; s++)
			tputs(" ", 0, tputc);
		tputs(tgetstr("mr", NULL), 0, tputc); // Active reverse video
		tputs(tgetstr("us", NULL), 0, tputc); // Active underline
		tputs(middle, 0, tputc);
		tputs(tgetstr("me", NULL), 0, tputc); // Remove all text style (ue for only underline);
		tputs(ft_itoa(term->winsize.ws_col), 0, tputc);
		//End test


		ft_bzero(key, 3);
		read(0, key, 3);

		// Arrow test
		if (ft_strcmp(key, tgetstr("kl", NULL)) == 0)
			tputs("Left Arrow", 0, tputc);
		// End test

		/*if (key[0] == 27)
		{
			if (key[1] == 91)
				tputs("Arrow\n", 0, tputc); // TODO : Passe pas une fois sur deux
			else if (key[1] == 0)
			{
				tputs(tgetstr("te", NULL), 0, tputc); 
				tcsetattr(0, TCSADRAIN, &(term->default_term));
				return (0);
			}
		}*/
	}



	// Ferme le plein ecran
	tcsetattr(0, TCSADRAIN, &(term->default_term));
	tputs(tgetstr("te", NULL), 0, tputc);

	return (1);
}
