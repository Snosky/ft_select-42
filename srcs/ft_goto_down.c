/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:33:54 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/16 02:35:35 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_goto_down(void)
{
	t_term	*term;
	int		i;

	term = ft_term();
	i = term->hover + 1;
	if (i >= term->nb_entries)
		i = 0;
	while (i != term->hover && !term->entries[i].visible)
	{
		if (i >= term->nb_entries)
			i = 0;
		i++;
	}
	term->hover = i;
}
