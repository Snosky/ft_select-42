/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:49:27 by tpayen            #+#    #+#             */
/*   Updated: 2016/12/02 02:21:28 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	init_entries_var(int ac)
{
	t_term	*term;

	term = ft_term();
	term->longest = 0;
	term->entries = NULL;
	term->padding_left = 0;
	term->nb_entries = ac - 1;
}

static void	save_entry(int i, char *s)
{
	t_term	*term;
	t_entry	entry;
	t_lstd	*tmp;
	int		len;

	term = ft_term();
	len = ft_strlen(s);
	entry.name = ft_strdup(s);
	entry.selected = 0;
	entry.id = i;
	if (!(tmp = ft_lstdnew(&entry, sizeof(t_entry))))
		ft_error("ft_select: Entries initialization failed.");
	ft_lstdadd(&(term->entries), tmp);
	if (len > term->longest)
		term->longest = len;
}

void		init_entries(int ac, char **av)
{
	t_term	*term;
	int		i;

	term = ft_term();
	init_entries_var(ac);
	i = 1;
	while (i < ac)
	{
		if (ft_strcmp("", av[i]))
			save_entry(i - 1, av[i]);
		else
			term->nb_entries--;
		i++;
	}
	if (term->nb_entries <= 0)
		sig_exit(0);
	term->hover = term->entries;
	winsize();
}
