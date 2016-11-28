/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 02:02:33 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/28 18:19:43 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	scroll_bar(void)
{
	t_term	*term;
	int		size_col;
	int		i;
	int		left;

	term = ft_term();
	size_col = term->winsize.ws_col / term->total_column;
	left = term->winsize.ws_col % term->total_column;
	i = 0;
	if (size_col == 0)
		return ;
	tputs(tgoto(term->cap[CM], left / 2, term->winsize.ws_row), 1, tputc);
	tputs(term->cap[MR], 0, tputc);
	while (i < term->winsize.ws_col - left)
	{
		if (i >= (term->padding_left * size_col) &&\
			   	i <= (term->padding_left + term->nb_column) * size_col)
		   tputs("#", 0, tputc);
		else	
			tputs("-", 0, tputc);
		i++;
	}
	tputs(term->cap[ME], 0, tputc);
}
