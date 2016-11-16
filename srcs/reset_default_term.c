/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_default_term.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 00:48:42 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/16 01:54:32 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	reset_default_term(void)
{
	t_term	*term;

	term = ft_term();

	ft_tputs("ve");
	ft_tputs("te");
	close(term->fd);
	tcsetattr(0, TCSADRAIN, &(term->default_term));
	free_entries();
}
