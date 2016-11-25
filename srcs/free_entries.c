/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_entries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:54:39 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/25 18:41:40 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	free_entries(void)
{
	t_term	*term;

	term = ft_term();
	/*while (--term->nb_entries >= 0)
		free(term->entries[term->nb_entries].name);
	free(term->entries);*/
}
