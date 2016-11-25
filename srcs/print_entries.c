/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entries.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:00:24 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/25 18:59:18 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
/*
static void	print_entry(int i, int *colcount, int *row, int nbrow)
{
	int		col;
	t_term	*term;

	term = ft_term();
	if (term->entries[i].visible == 0)
		return ;
	if (*row >= nbrow)
	{
		*row = 0;
		(*colcount)++;
	}
	if (*colcount >= term->nb_column)
		return ;
	col = *colcount * (term->longest + 2);
	tput<S-F7>s(tgoto(term->cap[CM], col, *row), 1, tputc);
	if (term->hover == i)
		tputs(term->cap[US], 0, tputc);
	if (term->entries[i].selected)
		tputs(term->cap[MR], 0, tputc);
	tputs(term->entries[i].name, 0, tputc);
	tputs(term->cap[ME], 0, tputc);
	(*row)++;
}

static int	jump_hidden(t_term *term)
{
	int tojmp;
	int	i;
	int	ret;

	tojmp = term->padding_left * term->winsize.ws_row;
	i = 0;
	ret = 0;
	while (i < tojmp)
	{
		if (term->entries[ret].visible)
			i++;
		ret++;
	}
	return (ret);
}

void		print_entries(void)
{
	t_term	*term;
	int		colcount;
	int		row;
	int		i;
	int		nbrow;

	term = ft_term();
	colcount = 0;
	row = 0;
	i = jump_hidden(term);
	nbrow = term->winsize.ws_row;
	if (tgetflag("hs"))
		nbrow = term->winsize.ws_row - tgetnum("ws");
	while (i < term->total_entries)
	{
		print_entry(i, &colcount, &row, nbrow);
		i++;
	}
}*/

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
		if (col < term->padding_left || col >= term->nb_column)
			continue ;
		tputs(tgoto(term->cap[CM], col * (term->longest + 2), i % term->winsize.ws_row), 1, tputc);
		print_entry();
		term->entries = term->entries->next;
		i++;
	}
}
