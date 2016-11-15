/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 00:57:21 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/15 01:52:06 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	init_term(void)
{
	t_term	*term;
	int		success;

	term = ft_term();
	term->name = getenv("TERM");
	if (term->name == NULL)
		term->name = "DEFAULT_TERM";
	success = tgetent(term_buffer, term->name);
	if (success < 0)
		ft_error("ft_select: error: Could not access the termcap data base.");
	else if (success == 0)
		ft_error(ft_strreplace("$1", term->name, \
			"ft_select: error: Terminal type $1 is not defined.", 0));
	if (tcgetattr(0, &(term->term)) == -1 || 
		tcgetattr(0, &(term->default_term)) == -1)
			ft_error("ft_select: error: Could not get terminal attributes.");
	term->term.c_lflag &= ~(ICANON | ECHO);
	term->term.c_cc[VMIN] = 1;
	term->term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &(term->term));
	ft_tputs("ti");
	ft_tputs("vi");
	winsize();
}
