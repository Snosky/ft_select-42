/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:15:52 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/28 16:59:37 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int	return_result(void)
{
	t_term	*term;
	int		i;
	t_entry	*entry;
	int		space;

	term = ft_term();
	i = 0;
	space = 0;
	reset_default_term();
	while (i < term->nb_entries)
	{
		entry = (t_entry *)term->entries->content;
		if (entry->selected)
		{
			if (space)
				ft_putchar(' ');
			space = 1;
			ft_putstr(entry->name);
		}
		term->entries = term->entries->next;
		i++;
	}
	return (-1);
}
