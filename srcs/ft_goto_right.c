/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 01:22:03 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/24 02:52:05 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	goto_start(void)
{
	t_term	*term;
	int	i;

	term = ft_term();
	i = term->hover - ((term->padding_left + 1) * term->winsize.ws_row);
	term->hover = (i % (term->nb_column + 1));
	//term->padding_left = 0;
}

void	ft_goto_right(void)
{
	t_term	*term;
	int		i;

	term = ft_term();
	i = 0;
	while (i < term->winsize.ws_row)
	{
		term->hover++;
		if (term->hover >= term->total_entries)
			goto_start();
		if (term->entries[term->hover].visible)
			i++;
	}
	/*if (term->hover >= \
			((term->nb_column + term->padding_left) * term->winsize.ws_row))
		term->padding_left++;*/
}
