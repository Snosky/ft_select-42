/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 00:51:18 by tpayen            #+#    #+#             */
/*   Updated: 2016/11/15 01:34:44 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		ft_tputs(char *id)
{
	char *s;

	if ((s = tgetstr(id, NULL)) == NULL)
		ft_error(ft_strreplace("%s", id, \
			"ft_select: error: Error on tgetstr(\"$s\")", 0));
	tputs(s, 0, tputc);
}
