/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_entries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:54:39 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/28 17:09:28 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	delete_entries(void *content, size_t size)
{
	t_entry	*entry;

	entry = (t_entry *)content;
	free(entry->name);
	free(entry);
	(void)size;
}

void	free_entries(void)
{
	t_term	*term;
	int		i;
	t_lstd	*next;

	term = ft_term();
	i = 0;
	while (i < term->nb_entries)
	{
		next = term->entries->next;
		ft_lstddelone(&term->entries, delete_entries);
		term->entries = next;
		i++;
	}
}
