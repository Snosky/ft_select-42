/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:58:32 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/24 02:52:33 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	refresh_screen(void)
{
	t_term	*term;

	term = ft_term();
	tputs(term->cap[CL], 0, tputc);
	refresh_padding_left();
	print_entries();
}
