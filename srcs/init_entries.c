/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:49:27 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/25 18:58:57 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	init_entries(int ac, char **av)
{
	t_term	*term;
	int		i;
	t_lstd	*tmp;
	t_entry	entry;

	term = ft_term();
	term->longest = 0;
	term->nb_entries = ac - 1;
	term->entries = NULL;
	i = 1;
	while (i < ac)
	{
		entry.name = ft_strdup(av[i]);
		entry.len = ft_strlen(av[i]);
		entry.selected = 0;
		if (!(tmp = ft_lstdnew(&entry, sizeof(t_entry))))
			ft_error("ft_select: Entries fail.");
		ft_lstdadd(&(term->entries), tmp);
		if (entry.len > term->longest)
			term->longest = entry.len;
		i++;
	}
	term->hover = term->entries;
}

/*
void	init_entries(int ac, char **av)
{
	t_term	*term;
	int		i;

	term = ft_term();
	term->longest = 0;
	term->nb_entries = ac - 1;
	term->total_entries = term->nb_entries;
	term->hover = 0;
	if (!(term->entries = \
				(t_entry *)malloc(sizeof(t_entry) * term->nb_entries)))
		ft_error("ft_select: error: Malloc entries failed.");
	i = 0;
	while (i < term->nb_entries)
	{
		term->entries[i].name = ft_strdup(av[i + 1]);
		term->entries[i].len = ft_strlen(av[i + 1]);
		term->entries[i].visible = 1;
		term->entries[i].selected = 0;
		if (term->entries[i].len > term->longest)
			term->longest = term->entries[i].len;
		i++;
	}
}*/
