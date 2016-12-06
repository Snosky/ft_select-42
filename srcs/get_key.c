/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:43:08 by tpayen            #+#    #+#             */
/*   Updated: 2016/12/06 14:17:34 by aalliot          ###   ########.fr       */
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
	return (1);
}

int			get_key(void)
{
	t_term	*term;
	int		key;

	term = ft_term();
	read(0, &key, sizeof(int));
	if (key == K_ESC)
	{
		reset_default_term();
		return (-1);
	}
	if (term->winsize.ws_col < term->longest + 2)
		return (0);
	return (get_key2(key));
}
