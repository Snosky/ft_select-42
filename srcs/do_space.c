/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:30:19 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/25 19:07:15 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	do_space(void)
{
	t_term	*term;
	int		i;

	term = ft_term();
	i = ((t_entry *)term->hover->content)->selected ? 0 : 1;
	((t_entry *)term->hover->content)->selected = i;
	ft_goto_down();
}
