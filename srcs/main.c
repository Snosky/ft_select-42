#include <ft_select.h>

#include <stdio.h>

int tputc(int c)
{
	return ((int)write(1, &c, 1));
}

int main	(void)
{
	char	*term_name;
	int		success;

	struct termios	default_term;
	struct termios	term;

	// On recup les informations obligatoire du terminal
	term_name = getenv("TERM");
	if (term_name == NULL)
		term_name = "DEFAULT_TERM"; //TODO : A voir si bien DEFAULT_TERM
	
	success = tgetent(term_buffer, term_name);
	if (success < 0)
		return (printf("Error 1\n")); // TODO : Gestion erreur, "Could not access the termcap data base."
	else if (success == 0)
		return (printf("Error 2\n")); // TODO : Error : "Terminal type $termtype is not defined."

	
	// On passe en mode pleine ecran
	tputs(tgetstr("ti", NULL), 0, tputc);
	
	
	if (tcgetattr(0, &term) == -1 || tcgetattr(0, &default_term))
		return (printf("Error 3\n"));

	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;

	tcsetattr(0, TCSADRAIN, &term);

	char key[3];

	while (1)
	{
		ft_bzero(key, 3);
		read(0, key, 3);

		if (key[0] == 27)
		{
			if (key[1] == 91)
				tputs("Arrow\n", 0, tputc); // TODO : Passe pas une fois sur deux
			else if (key[1] == 0)
			{
				ft_putstr_fd(tgetstr("te", NULL), 1); 
				tcsetattr(0, TCSADRAIN, &default_term);
				return (0);
			}
		}
	}



	// Ferme le plein ecran
	tcsetattr(0, TCSADRAIN, &default_term);
	tputs(tgetstr("te", NULL), 0, tputc);

	return (1);
}
