/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:43:08 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/21 01:24:45 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int	get_key()
{
	t_term	*term;
	int		key;

	term = ft_term();
	read(0, &key, sizeof(int));
	if (key == K_UP)
		ft_goto_up();
	else if (key == K_DOWN)
		ft_goto_down();
	else if (key == K_LEFT)
		term->hover -= term->winsize.ws_row;
	else if (key == K_RIGHT)
		ft_goto_right();
	else if (key == K_DELETE || key == K_BACKSPACE)
	{
		term->entries[term->hover].visible = 0;
		term->nb_entries--;
		ft_goto_down();
	}
	else if (key == K_SPACE)
	{
		term->entries[term->hover].selected = (term->entries[term->hover].selected) ? 0 : 1;
		ft_goto_down();
	}
	else if (key == K_ESC)
		return (-1);
	return (1);
}
