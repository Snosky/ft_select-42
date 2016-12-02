/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:58:32 by tpayen            #+#    #+#             */
/*   Updated: 2016/12/02 02:31:12 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	too_small(void)
{
	t_term	*term;
	int		i;

	term = ft_term();
	i = term->winsize.ws_row * term->winsize.ws_col;
	while (i)
	{
		tputs("X", 0, tputc);
		i--;
	}
	return ;
}

void		refresh_screen(void)
{
	t_term	*term;

	term = ft_term();
	term->padding_bottom = 0;
	if (term->nb_column < term->total_column)
		term->padding_bottom = 1;
	tputs(term->cap[CL], 0, tputc);
	if (term->winsize.ws_col < term->longest + 2)
		return (too_small());
	refresh_padding_left();
	if (term->nb_column < term->total_column)
		scroll_bar();
	print_entries();
}
