/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 01:22:03 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/21 01:48:28 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

// TODO : Si element delete ?
// TODO:  Pas mal de truc a revoir, le tmp correspond pas vraiment a la position du curseur comme il le devrait mais a quel entry est hover
void	ft_goto_right(void)
{
	t_term	*term;
	int		tmp;

	term = ft_term();
	tmp = term->hover + term->winsize.ws_row;
	if (tmp > term->nb_entries)
	{
		term->padding_left = 0;
		term->hover = 0;
		return ;
	}
	if (tmp >= term->winsize.ws_row * term->nb_column)
		term->padding_left++;
	term->hover = tmp;
}
