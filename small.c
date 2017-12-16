#include "h_fillit.h"

int fit_in_square(int side, t_tetr *list)
{
	char *sqr;
	int res;

	sqr = create_sqr(side);
	res = try(side, list, sqr, 0);
	if (res == 0)
		return (0);
	return (1);
}

int print_one(char *single)
{
	int len;

	single = ft_strtrim(single);
	len = ft_strlen(single);
	if (len == 13 || len == 4)
		return (4);
	else if (len > 6)
		return (3);
	else if (len == 5)
		return (3);
	else if (len == 6)
		return (2);
	return (1);
}

void print_result(char *sqr, int side)
{
	int i;

	i = 0;
	while (sqr[i])
	{
		if (i % side == 0 && i != 0)
			printf("\n");
		printf("%c", sqr[i]);
		i++;
	}
	printf("\n");
}

void clear(char *sqr)
{
	while (*sqr)
	{
		*sqr = '.';
		sqr++;
	}
}

int make_square(int number)
{
	int i;

	i = 2;
	while ((i * i) < number)
		i++;
	return (i);
}
