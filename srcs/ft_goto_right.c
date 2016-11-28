/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 01:22:03 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/28 18:06:11 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_goto_right(void)
{
	t_term	*term;
	int		i;

	term = ft_term();
	i = 0; 
	while (i < term->winsize.ws_row - term->padding_bottom)
	{
		term->hover = term->hover->next;
		i++;
	}
}
