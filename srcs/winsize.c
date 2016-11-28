/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:49:09 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/28 17:31:36 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	winsize(void)
{
	t_term	*term;

	term = ft_term();
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, (char *)&term->winsize) < 0)
		ft_error("ft_select: error: Can't get terminal size.");
	if (term->nb_entries - 2)
	{
		term->nb_column = term->winsize.ws_col / (term->longest + 2);
		term->total_column = (term->nb_entries / term->winsize.ws_row) + 1;
		//if (term->nb_column >= term->total_column)
		//	term->padding_left = 0;
	}
}
