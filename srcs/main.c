#include <ft_select.h>

#include <stdio.h>

int	main(int ac, char **av)
{
	init_entries(ac, av);
	init_term();
	init_signals();
	
	while (42)
	{
		refresh_screen();
		if (get_key() == -1)
			break;
	}
	reset_default_term();
}
