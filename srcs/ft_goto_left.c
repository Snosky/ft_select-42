/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 01:39:07 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/22 16:06:40 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_goto_left(void)
{
	t_term	*term;
	int		i;

	term = ft_term();
	i = term->winsize.ws_row;
	while (i > 0)
	{
		term->hover--;
		if (term->hover < 0)
		{
			term->hover = term->total_entries;
			term->padding_left = term->total_column - term->nb_column;
		}
		if (term->entries[term->hover].visible)
			i--;
	}
	if (term->hover < (term->padding_left * term->winsize.ws_row))
		term->padding_left--;
}
