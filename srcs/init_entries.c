/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:49:27 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/28 17:49:16 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	init_entries(int ac, char **av)
{
	t_term	*term;
	int		i;
	t_lstd	*tmp;
	t_entry	entry;
	int		len;

	term = ft_term();
	term->longest = 0;
	term->nb_entries = ac - 1;
	term->entries = NULL;
	i = 1;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		entry.name = ft_strdup(av[i]);
		entry.selected = 0;
		entry.id = i - 1;
		if (!(tmp = ft_lstdnew(&entry, sizeof(t_entry))))
			ft_error("ft_select: Entries fail.");
		ft_lstdadd(&(term->entries), tmp);
		if (len > term->longest)
			term->longest = len;
		i++;
	}
	term->hover = term->entries;
	term->padding_left = 0;
	winsize();
}
