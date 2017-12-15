#include "h_fillit.h"

int first_check(char *s)
{
	int i = 0;
	int number = 0;

	i = 0;
	while (i < 20)
	{
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n') // checks for valid characters
			return (0);
		if (s[i] == '\n' && ((i + 1) % 5 != 0)) // checks that '\n' is each fifth element
			return (0);
		if (s[i] == '#') 
			number++;
		i++;
	}
	if (number != 4) // checks that exactly 4 '#'
		return (0);
	return (1);
}

int second_check(char *arr, int row, int j) 
{
	int touches;

	touches = 0; 
  	while(row < 4)
  	{
   		j = 0;
   		while (j < 4)
    	{
    		if (arr[row * 4 + j] != '.')
    		{
    			if ((row != 0) && (arr[(row - 1) * 4 + j] != '.'))
    				touches++;
    			if ((row != 3) && (arr[(row + 1) * 4 + j] != '.'))
    				touches++;
    			if ((j != 0) && (arr[row * 4 + j - 1] != '.'))
    				touches++;
    			if ((j != 3) && (arr[row * 4 + j + 1] != '.'))
    				touches++;
    		}
    		j++;
    	}
    	row++;
    }
    return (touches);
}

void create_ar(char *s, char *arr, int number)
{
	int row;
	int j;

	row = 0;
  	while(row < 4)
  	{
   		j = 0;
   		while (j < 4)
    	{
    		if (*s != '\n')
    		{
				if (*s == '#')
					arr[row * 4 + j] = 'A' + number;
				else
					arr[row * 4 + j] = '.';
    			j++;
    		}
    		s++;
    	}
    	row++;
   	}
}

int validate_input(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		write(1, "show usage\n", 10);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY); //TODO: do need to close ?
	if (fd == -1)
	{
		printf("error / usage ?\n");
		exit(0);
	}
	return (fd);
}
