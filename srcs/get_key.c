/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:43:08 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/22 16:31:46 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int	get_key(void)
{
	t_term	*term;
	int		key;

	term = ft_term();
	read(0, &key, sizeof(int));
	if (key == K_UP)
		ft_goto_up();
	else if (key == K_DOWN)
		ft_goto_down();
	else if (key == K_LEFT)
		ft_goto_left();
	else if (key == K_RIGHT)
		ft_goto_right();
	else if (key == K_DELETE || key == K_BACKSPACE)
		ft_delete();
	else if (key == K_SPACE)
		do_space();
	else if (key == K_RETURN)
		return (return_result());
	else if (key == K_ESC)
	{
		reset_default_term();
		return (-1);
	}
	return (1);
}
