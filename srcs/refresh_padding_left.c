/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_padding_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 02:45:16 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/29 18:32:47 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	refresh_padding_left(void)
{
	t_term	*term;
	t_entry	*entry;
	int		last;
	int		first;
	int		row;

	term = ft_term();
	entry = (t_entry *)term->hover->content;
	row = term->winsize.ws_row - term->padding_bottom;
	while (1)
	{
		first = term->padding_left * row;
		last = (term->padding_left + term->nb_column) * row - 1;
		if (term->total_column < term->nb_column)
		{
			term->padding_left = 0;
			break ;
		}
		if (term->padding_left < 0)
			term->padding_left = term->total_column - term->nb_column;
		else if (term->padding_left > term->total_column - term->nb_column)
			term->padding_left = 0;
		else if (entry->id < first)
			term->padding_left--;
		else if (entry->id > last)
			term->padding_left++;
		else
			break ;
	}
}
