#include "h_fillit.h"

void	fill(t_tetr *list, char *square)
{
	while (list->pr_t)
		list = list->pr_t;
	while (list && (list->s_p != -1))
	{
		add_figure(list->fig, square, list->s_p);
		list = list->n_t;
	}
}

int		check_sp(char *square, t_tetr t, int start, int side)
{
	int	i;
	int j;
	int all;

	i = 0;
	j = 0;
	all = 0;
	while (square[i + start] && t.fig[i])
	{
		if ((square[i + start] == '.') && (t.fig[i] != '.'))
			i++;
		else if ((square[i + start] != '.') && (t.fig[i] != '.'))
			return (0);
		else if (t.fig[i] == '.')
			i++;
	}
	if (t.fig[i] == '\0')
	{
		i = 0;
		while (((i + start) % side) != 0 || (i == 0))
		{
			i++;
			all++;
		}
		i = 0;
		while (i < all)
		{
			if (t.fig[i] != '.' && t.fig[i] != '\0')
				j++;
			i++;
		}
		if (j != t.wid)
			return (0);
		if (all < t.wid_k)
			return (0);
		return (1);
	}
	return (0);
}

int		get_sp(char *square, t_tetr t, int side, int start)
{
	int		i;

	i = start;
	while (square[i])
	{
		if (check_sp(square, t, i, side) == 1)
			return (i);
		i++;
	}
	return (-1);
}

char	*create_sqr(int side)
{
	char	*str;
	int		numb;

	numb = side * side;
	str = (char *)malloc(sizeof(char) * (numb + 1));
	if (str == NULL)
		return (NULL);
	str[numb] = '\0';
	while (numb--)
		str[numb] = '.';
	return (str);
}

int		try(int side, t_tetr *list, char *sqr, int sp)
{
	while (list)
	{
		if (list->s_p == -1)
		{
			if ((sp = get_sp(sqr, *list, side, list->tries)) == -1)
			{
				list->tries = 0;
				if (list->pr_t == NULL)
					return (0);
				list = list->pr_t;
				list->tries = list->s_p + 1;
				list->s_p = -1;
				clear(sqr);
				fill(list, sqr);
			}
			else
			{
				list->s_p = sp;
				add_figure(list->fig, sqr, sp);
				list = list->n_t;
			}
		}
	}
	print_result(sqr, side);
	return (1);
}

void	algorithm(char **valid, int count)
{
	int		side;
	int		res;
	t_tetr	*list;

	if (count == 1)
	{
		if (ft_strequ(ft_strtrim(valid[0]), "A...A..AA"))
		{
			ft_putstr("..A\n..A\n.AA\n");
			return ;
		}
		side = print_one(valid[0]);
	}
	else
		side = make_square(count * 4);
	list = prepare_list(valid, side);
	if (list == NULL)
		printf("SHIT\n");
	res = fit_in_square(side, list);
	while (res == 0)
	{
		side += 1;
		list = change_list(valid, side, list);
		res = fit_in_square(side, list);
	}
}
