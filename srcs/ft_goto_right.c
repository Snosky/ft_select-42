/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 01:22:03 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/29 18:23:23 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_goto_right(void)
{
	t_term	*term;
	t_entry	*entry;
	int		i;
	int		row;

	term = ft_term();
	if (term->total_column == 1)
		return ;
	row = term->winsize.ws_row - term->padding_bottom;
	entry = (t_entry *)term->hover->content;
	i = 0;
	if (entry->id + row >= term->nb_entries)
	{
		i = row - (term->nb_entries % ((term->total_column - 1) * row));
		if (entry->id + row < row * term->total_column)
			i -= (row - (entry->id % row)) - 1;
	}
	while (i < row)
	{
		term->hover = term->hover->next;
		i++;
	}
}
