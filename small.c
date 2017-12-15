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

