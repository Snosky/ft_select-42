/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:58:32 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/15 02:08:36 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	refresh_screen(void)
{
	t_term	*term;

	term = ft_term();

	ft_tputs("cl");

	char *pos = tgetstr("cm", NULL);
	char *test = "~FT_SELECT BY TPAYEN~";
	int	center = (term->winsize.ws_col / 2) - (ft_strlen(test) / 2);
	int center2 = (term->winsize.ws_row / 2);
	tputs(tgoto(pos, center, center2), 1, tputc);
	tputs(test, 0, tputc);
}
