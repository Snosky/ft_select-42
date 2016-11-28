/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:05:49 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/28 18:20:29 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	init_signals(void)
{
	signal(SIGWINCH, sig_win_resize);
	signal(SIGINT, sig_exit);
	signal(SIGABRT, sig_exit);
	signal(SIGFPE, sig_exit);
	signal(SIGILL, sig_exit);
	signal(SIGSEGV, sig_exit);
	signal(SIGTERM, sig_exit);
	signal(SIGKILL, sig_exit);
	signal(SIGQUIT, sig_exit);
	signal(SIGSTOP, sig_stop);
	signal(SIGCONT, sig_cont);
}
