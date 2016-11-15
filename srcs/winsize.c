/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:49:09 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/15 01:50:31 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	winsize(void)
{
	t_term	*term;

	term = ft_term();
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, (char *)&term->winsize) < 0)
		ft_error("ft_select: error: Can't get terminal size.");
}
