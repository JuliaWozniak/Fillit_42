#include "h_fillit.h"


char 	*check_validity(char buf[], int numb)
{
	int res;
  	char *str;

	res = first_check(buf);
	if (res == 0)
		return (NULL);
	str = (char *)malloc(17 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[16] = '\0';
	create_ar(buf, str, numb);
	res = second_check(str, 0, 0);
	if (res < 6)
		return (NULL);
	return (str);
}


/* read file
	takes a valid file descriptor
	opens a file

	malloc array of pointers (27)

	while (read)
	check_validity(buf);
	if valid - add tetramino to array
	if end of file and everything is valid - add NULL to the end of array
	if any error - free all previous and array
	print error

	returns array of pointers to valid tetraminos or NULL
	closes a file
*/

char **read_file(int fd) //TODO: make it do not malloc before check for validation. rather a two-dimensional array of pointers to strings [26][16]
{
	int		n;
	int		count = 0;
	char	buf[22];
	char  	*res;
	char  **res_ar;

	if ((res_ar = (char **)malloc(sizeof(char *) * 27)) == NULL)
		return NULL;
	while ((n = read(fd, buf, 21)))
		{
			buf[n] = '\0';
			if (buf[0] == '\n')
				return NULL;
			if (n == 21 && buf[20] != '\n') 
				return NULL;
			res = check_validity(buf, count);
			if (res != NULL)
				res_ar[count] = res;
			else
			{
				// clear what has been created before
				return NULL;
			}
			count++;
			if (count > 26) 
			{
				// clear what has been created
				return NULL; 
			}
		}
		res_ar[count] = NULL;
		return (res_ar);
}

/*	validate input 

	takes:	program input

	returns:	nothing
	
	1. checks input
	2. shows usage if not right
	3. checks file descriptor
	4. shows usage if not right
*/




int main(int argc, char **argv)
{
	char **valid_char;
	int fd;

	fd = validate_input(argc, argv);
	valid_char = read_file(fd);
	printf("HERE 9\n");
	if (valid_char != NULL)
	{
		printf("HERE 10\n");
		
		int i;

		i = 0;
		while (valid_char[i])
		{
			i++;
		}
		algorithm(valid_char, i);
		// algorithm
	}
	return (0);
}

/*
	TASKS

	- write func that frees everything in case of error
	- create func that creates tetramininu
	- create func that iterates and calls the func that creates tetramininu
		and returns first item of a list
	- refactor read file
	- trim string
	- deal with usage
	- deal with error
	- deal with exit
	- deal with close file 
	- width of figure

	- 
	
*/
