/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:43:08 by tpayen            #+#    #+#             */
/*   Updated: 2016/12/02 02:26:37 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int	get_key2(int key)
{
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

int				get_key(void)
{
	t_term	*term;
	int		key;

	term = ft_term();
	if (term->winsize.ws_col < term->longest + 2)
		return (1);
	read(0, &key, sizeof(int));
	return (get_key2(key));
}
