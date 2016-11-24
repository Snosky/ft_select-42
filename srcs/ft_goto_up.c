/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:20:51 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/24 02:56:35 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		ft_goto_up(void)
{
	t_term	*term;
	int		i;

	term = ft_term();
	i = term->hover - 1;
	if (i < 0)
		i = term->total_entries - 1;
	while (i != term->hover && !term->entries[i].visible)
	{
		if (i < 0)
			i = term->total_entries - 1;
		i--;
	}
	term->hover = i;
}
