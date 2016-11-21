/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 02:02:33 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/21 02:23:04 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/* TODO : Pas dur */
void	scroll_bar(void)
{
	t_term	*term;
	int		i;
	int		total_col;
	int		bar_size;

	term = ft_term();
	i = 0;
	total_col = (term->nb_entries / term->winsize.ws_row) + 1;
	bar_size = ((term->nb_column / total_col) * 100);
	if (total_col <= term->nb_column)
		return ;

	/* Ceci est un test */
	tputs(tgoto(term->cap[CM], 0, term->winsize.ws_row), 1, tputc);
	while (i < term->winsize.ws_col)
	{
		tputs("-", 0, tputc);
		i++;
	}
}
