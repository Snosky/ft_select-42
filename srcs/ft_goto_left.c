/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 01:39:07 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/24 04:32:20 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*void	ft_goto_left(void)
{
	t_term	*term;
	int		lastcol;
	int		oldhover;

	term = ft_term();
	lastcol = term->winsize.ws_row - (term->nb_entries % term->winsize.ws_row);
	oldhover = term->hover;
	term->hover -= term->winsize.ws_row;
	if (term->hover < 0)
	{
		term->hover = term->total_entries + lastcol - term->winsize.ws_row + oldhover;
		if (term->hover >= term->total_entries)
			term->hover = term->total_entries;
	}
	oldhover = term->hover;
	ft_goto_up();
	if (oldhover != term->hover)
		term->hover += 1;
}
*/
void	ft_goto_left(void)
{
	t_term	*term;
	int		jmp;

	term = ft_term();
	jmp = term->winsize.ws_row;
	if (term->hover - jmp < 0)
	{
		jmp -= (term->nb_entries % term->winsize.ws_row);
		//jmp = jmp - term->hover - 1;
		term->hover = term->total_entries - 1;
	}
	while (jmp)
	{
		if (term->entries[term->hover].visible)
			jmp--;
		term->hover--;
	}
}
