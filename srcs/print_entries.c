/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entries.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:00:24 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/25 19:29:15 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void		print_entry(void)
{
	t_term	*term;
	t_entry	*entry;

	term = ft_term();
	entry = (t_entry *)term->entries->content;
	if ((t_entry *)term->hover->content == entry)
		tputs(term->cap[US], 0, tputc);
	if (entry->selected)
		tputs(term->cap[MR], 0, tputc);
	tputs(entry->name, 0, tputc);
	tputs(term->cap[ME], 0, tputc);
}

void	print_entries(void)
{
	t_term	*term;
	int		i;
	int		col;

	term = ft_term();
	i = 0;
	col = 0;
	while (i < term->nb_entries)
	{
		if (i && i % term->winsize.ws_row == 0)
			col++;
		if (col >= term->padding_left && col < term->nb_column)
		{
			tputs(tgoto(term->cap[CM], col * (term->longest + 2), i % term->winsize.ws_row), 1, tputc);
			print_entry();
		}
		term->entries = term->entries->next;
		i++;
	}
}
