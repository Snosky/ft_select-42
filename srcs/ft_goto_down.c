/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:33:54 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/25 19:48:35 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		ft_goto_down(void)
{
	t_term	*term;

	term = ft_term();
	term->hover = term->hover->next;
	term->hoverid++;
	if (term->hover == term->entries)
		term->hoverid = 1;
}
