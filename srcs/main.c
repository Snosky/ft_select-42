/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:33:09 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/25 18:22:48 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	init_entries(ac, av);
	init_term();
	init_signals();
	
	while (42)
	{
		refresh_screen();
		if (get_key() == -1)
			break ;
	}
	free_entries();
	return (0);
}
