/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entries.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:00:24 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/16 02:33:21 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	print_entries(void)
{
	t_term	*term;
	int		col;
	int		colcount;
	int		row;
	int		i;

	term = ft_term();
	colcount = 0;
	row = 0;
	i = 0;
	while (i < term->nb_entries)
	{
		if (term->entries[i].visible == 0)
		{
			i++;
			continue;
		}

		if (row > term->winsize.ws_row)
		{
			row = 0;
			colcount++;
		}
		col = colcount * (term->longest + 2);
		tputs(tgoto(term->cap[CM], col, row), 1, tputc);
		if (term->hover == i)
			tputs(term->cap[US], 0, tputc);
		if (term->entries[i].selected)
			tputs(term->cap[MR], 0, tputc);
		tputs(term->entries[i].name, 0, tputc);
		tputs(term->cap[ME], 0, tputc);
		row++;
		i++;
	}
}
