/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_stop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:18:21 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/28 18:21:16 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	sig_stop(int i)
{
	t_term	*term;
	char	cp[2];

	(void)i;
	if (isatty(1))
	{
		term = ft_term();
		cp[0] = term->term.c_cc[VSUSP];
		cp[1] = 0;
		reset_default_term();
		ioctl(0, TIOCSTI, cp);
		ft_putstr("\b\b\033[0J");
		signal(SIGTSTP, SIG_DFL);
	}
}
