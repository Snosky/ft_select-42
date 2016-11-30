/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_cont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:21:35 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/28 18:24:47 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	sig_cont(int i)
{
	t_term	*term;

	(void)i;
	term = ft_term();
	tcsetattr(0, TCSADRAIN, &(term->term));
	ft_tputs("ti");
	ft_tputs("vi");
	init_signals();
	winsize();
	refresh_screen();
}
