/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 01:22:03 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/25 20:15:59 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_goto_right(void)
{
	t_term	*term;
	int		i;

	term = ft_term();
	i = 0; 
	while (i < term->winsize.ws_row)
	{
		term->hover = term->hover->next;
		term->hoverid++;
		if (term->hover == term->entries)
			term->hoverid = 0;
		i++;
	}
}
