/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 01:39:07 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/25 19:03:15 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_goto_left(void)
{
	t_term	*term;
	int		i;

	term = ft_term();
	i = 0;
	while (i < term->winsize.ws_row)
	{
		term->hover = term->hover->prev;
		i++;
	}
}
