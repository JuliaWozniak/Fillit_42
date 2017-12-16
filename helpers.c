#include "h_fillit.h"

void add_figure(char *fig, char *square, int s_p)
{
	int i;

	i = 0;
	while (fig[i])
	{
		if (fig[i] != '.')
			square[i + s_p] = fig[i];
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	if (s == NULL)
		return ;
	while (*s)
		ft_putchar(*(s++));
}

int find_next(char *str)
{
	int i;

	i = 1;
	while (*str++ == '.')
		i++;
	return (i);
}

int switch_k(int k, int side)
{
	if (k == 1)
		return (side - 3);
	else if (k == 2)
		return (side - 2);
	else if (k == 3)
		return (side - 1);
	else
		return (0);
}
