/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 01:39:07 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/25 16:32:22 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_goto_left(void)
{
	t_term	*term;
	int		jmp;
	int		oldhover;

	term = ft_term();
	jmp = term->winsize.ws_row;
	if (term->hover - jmp < 0)
		return ;
	oldhover = term->hover;
	while (jmp)
	{
		if (term->hover == 0)
		{
			term->hover = oldhover;
			return ;
		}
		if (term->entries[term->hover].visible)
			jmp--;
		term->hover--;
	}
}
