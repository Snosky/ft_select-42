/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:33:54 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/22 16:32:28 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	do_down(int *i, t_term *term)
{
	if (*i >= term->total_entries)
	{
		term->padding_left = 0;
		*i = 0;
	}
	if (*i >= \
			(term->nb_column * term->winsize.ws_row) + \
			(term->padding_left * term->winsize.ws_row))
		term->padding_left++;
}

void		ft_goto_down(void)
{
	t_term	*term;
	int		i;

	term = ft_term();
	i = term->hover + 1;
	do_down(&i, term);
	while (i != term->hover && !term->entries[i].visible)
	{
		do_down(&i, term);
		i++;
	}
	term->hover = i;
}
