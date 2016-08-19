#include <ft_select.h>

static t_elem	*save_elems(char **av)
{
	t_elem	*ret;
	t_elem	*new;
	t_elem	*first;
	int	i;

	ret = NULL;
	i = 1;
	while (av[i])
	{
		if (!(new = (t_elem *)malloc(sizeof(t_elem))))
			return (NULL);
		new->content = av[i];
		if (ret == NULL)
		{
			ret = new;
			ret->next = ret;
			ret->prev = ret;
			first = ret;
		}
		else
		{
			new->next = ret;
			new->prev = first;
			ret->prev = new;
			first->next = new;
			ret = new;	
		}
		i++;
	}
	return (ret);
}

size_t	getlonger(t_elem *elem, int nb)
{
	size_t	max;

	max = 0;
	while (nb)
	{
		if (ft_strlen(elem->content) > max)
			max = ft_strlen(elem->content);
		elem = elem->next;
		nb--;
	}
	return (max);
}

void	print_len(char *s, size_t len)
{
	ft_putstr(s);
	len -= ft_strlen(s);
	if (len)
	{
		while (len)
		{
			ft_putchar(' ');
			len--;
		}	
	}
}

int	test(int c)
{
	write(2, &c, 1);
	return (1);
}

int	main(int ac, char **av)
{
	t_elem	*elem;
	char	*termtype;
	char	termbuff[2048];
	
	termtype = getenv("TERM");
	tgetent(termbuff, termtype);
	if (ac > 1)
	{
		elem = save_elems(av);

	}
	return (0);
}

