/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 00:57:21 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/21 01:18:34 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	init_term2(void)
{
	t_term	*term;

	term = ft_term();
	if ((term->cap[CL] = tgetstr("cl", NULL)) == NULL ||
		(term->cap[US] = tgetstr("us", NULL)) == NULL ||
		(term->cap[UE] = tgetstr("ue", NULL)) == NULL || 
		(term->cap[MR] = tgetstr("mr", NULL)) == NULL ||
		(term->cap[ME] = tgetstr("me", NULL)) == NULL ||
		(term->cap[CM] = tgetstr("cm", NULL)) == NULL)
		ft_error("ft_select: error: Can't find a termcap.");
	ft_tputs("ti");
	ft_tputs("vi");
	term->padding_left = 0;
	winsize();
}

void		init_term(void)
{
	t_term	*term;
	int		success;

	term = ft_term();
	if ((term->fd = open(ttyname(STDIN_FILENO), O_WRONLY)) == -1)
		ft_error("ft_select: error: Can't get file descriptor.");
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
	init_term2();
}
