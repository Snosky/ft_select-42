/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_padding_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 02:45:16 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/24 03:15:29 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	refresh_padding_left(void)
{
	t_term	*term;

	term = ft_term();
	while (1)
		if (term->total_column <= term->nb_column)
		{
			term->padding_left = 0;
			break ;
		}
		else if (term->hover <= (term->padding_left * term->winsize.ws_row) - 1)
			term->padding_left--;
		else if (term->hover >= (term->nb_column * term->winsize.ws_row) + (term->padding_left * term->winsize.ws_row))
			term->padding_left++;
		else
			break ;
}
