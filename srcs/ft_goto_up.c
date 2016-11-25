/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:20:51 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/25 19:48:00 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		ft_goto_up(void)
{
	t_term	*term;

	term = ft_term();
	term->hover = term->hover->prev;
	term->hoverid--;
	if (term->hover == term->entries->prev)
		term->hoverid = term->nb_entries;
}
