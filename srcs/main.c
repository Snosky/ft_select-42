/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:33:09 by tpayen            #+#    #+#             */
/*   Updated: 2016/12/06 14:05:39 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int	main(int ac, char **av)
{
	int	key_press;

	if (ac == 1)
		return (0);
	if (init_term() == -1)
		return (0);
	init_entries(ac, av);
	init_signals();
	refresh_screen();
	while (42)
	{
		key_press = get_key();
		if (key_press == 0)
			continue ;
		if (key_press == -1)
			break ;
		refresh_screen();
	}
	free_entries();
	return (0);
}
