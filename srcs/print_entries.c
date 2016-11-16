/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entries.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:00:24 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/16 20:45:10 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	print_entry(int i, t_term *term, int *colcount, int *row, int nbrow)
{
	int	col;

	if (term->entries[i].visible == 0)
		return ;
	if (*row > nbrow)
	{
		*row = 0;
		(*colcount)++;
	}
	col = *colcount * (term->longest + 2);
	tputs(tgoto(term->cap[CM], col, *row), 1, tputc);
	if (term->hover == i)
		tputs(term->cap[US], 0, tputc);
	if (term->entries[i].selected)
		tputs(term->cap[MR], 0, tputc);
	tputs(term->entries[i].name, 0, tputc);
	tputs(term->cap[ME], 0, tputc);
	(*row)++;
}

void	print_entries(void)
{
	t_term	*term;
	int		colcount;
	int		row;
	int		i;
	int		nbrow;

	term = ft_term();
	colcount = 0;
	row = 0;
	i = 0;
	nbrow = term->winsize.ws_row;
	if (tgetflag("hs"))
		nbrow = term->winsize.ws_row - tgetnum("ws");
	while (i < term->nb_entries)
	{
		print_entry(i, term, &colcount, &row, nbrow);
		i++;
	}
}
