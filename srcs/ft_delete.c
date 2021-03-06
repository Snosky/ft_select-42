/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:18:31 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/29 18:33:29 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	free_entry(void *entry, size_t size)
{
	(void)size;
	free(((t_entry *)entry)->name);
	free(entry);
}

void	ft_delete(void)
{
	t_term	*term;
	t_lstd	*next;

	term = ft_term();
	term->nb_entries--;
	next = term->hover->next;
	if (term->hover == term->entries)
		term->entries = next;
	ft_lstddelone(&term->hover, free_entry);
	if (term->nb_entries == 0)
		sig_exit(0);
	term->hover = next;
	winsize();
}
