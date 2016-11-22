/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:20:51 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/22 16:32:58 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	do_up(int *i, t_term *term)
{
	if (*i < 0)
	{
		if (term->total_column > term->nb_column)
			term->padding_left = term->total_column - term->nb_column;
		*i = term->total_entries - 1;
	}
}

/* TODO : paddding_left-- quand en haut a droite; */
void		ft_goto_up(void)
{
	t_term	*term;
	int		i;

	term = ft_term();
	i = term->hover - 1;
	do_up(&i, term);
	while (i != term->hover && !term->entries[i].visible)
	{
		do_up(&i, term);
		i--;
	}
	term->hover = i;
}
