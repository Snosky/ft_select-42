/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 01:39:07 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/21 01:47:33 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_goto_left(void)
{
	t_term	*term;
	int		tmp;

	term = ft_term();
	tmp = term->hover - term->winsize.ws_row;
	if (tmp < 0)
	{
		term->padding_left = term->nb_entries / term->nb_column;
		term->hover = term->nb_entries;
		return ;
	}

}
