#include <libft.h>
#include <termios.h>
#include <term.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
static int	ft_putchar_tm(int c)
{
	write(2, &c, 1);
	return (0);
}

int	main(void)
{
	char		*termtype;
	struct termios	default_term;
	struct termios	term;
	int		success;
	char		termbuffer[2048];

	// On recupere le type du terminal ( "screen" en general )
	if ((termtype = getenv("TERM")) == 0)
	{
		printf("Specift a terminal type 'setenv TERM <type>.\n");
		exit(EXIT_FAILURE);
	}
	
	// Tgetent gare en static toutes les infos du terminal est les autres i
	// fontions l'utilisent.
	// La var success pour la gestion d'erreur
	success = tgetent(termbuffer, termtype);
	if (success < 0)
	{
		printf("Could not access the termcap data base.\n");
		exit(EXIT_FAILURE);
	}
	if (success == 0)
	{
		printf("Terminal type is not defined");
		exit(EXIT_FAILURE);
	}

	//On recup la structure du terminal afin de reset le terminal en fin
	if (tcgetattr(0, &default_term) == -1)
	{
		printf("Error on tcgetattr.\n");
		exit(EXIT_FAILURE);
	}
	term = default_term;

	// On clean le terminal
	//tputs(tgetstr("cl", NULL), 1, ft_putchar_tm);	

	// On cache le curseur
	//tputs(tgetstr("vi", NULL), 1, ft_putchar_tm);

	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &term);

	// Affichage
	char	key[3];

	while (1)
	{
		read(0, key, 3);
		// Arrow keys
		//if (ft_strcmp("\027[A", key) == 0)
		//		ft_putstr("Arrow Up");
		/*if (key[0] == '\027')
		{
			if (key[2] == 'A')
				ft_putstr("Arrow Up");
			else if (key[2] == 'B')
				ft_putstr("Arrow Down");
		}*/
		//else if (ft_strcmp(key, "\027") == 0)
		//		ft_putstr("Exit putain");
		//else
				ft_putstr(key);
		ft_bzero(key, 3);
	}

	// On remet le terminal comme d'hab
	if (tcsetattr(0, TCSANOW, &default_term) == -1)
	{
		printf("Deso pas deso le terminal c'est pas remi.\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}
