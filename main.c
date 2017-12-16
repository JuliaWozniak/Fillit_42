#include "h_fillit.h"

char *check_validity(char buf[], int numb)
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
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char *inner_read(char buf[], int n, int count)
{
	char *res;

	if (buf[0] == '\n' || buf[0] == '\0')
		return (NULL);
	if (n == 21 && buf[20] != '\n') 
		return NULL;
	res = check_validity(buf, count);
	return (res);
}

char **read_file(int fd, int n, int count)
{
	char	buf[22];
	char  	*res;
	char  	**res_ar;
	char 	end[2];

	if ((res_ar = (char **)malloc(sizeof(char *) * 27)) == NULL)
		return NULL;
	while ((n = read(fd, buf, 21)))
		{
			buf[n] = '\0';
			if ((res = inner_read(buf, n, count))!= NULL)
				res_ar[count++] = res;
			else
				return (NULL);
			if (count > 26) 
				return (NULL); 
			end[0] = buf[n - 2];
			end[1] = buf[n - 1];
		}
		if (count == 0)
			return (0);
		if (end[0] == '\n' && end[1] == '\n')
				return (NULL);	
		res_ar[count] = NULL;
		return (res_ar);
}


int main(int argc, char **argv)
{
	char **valid_char;
	int fd;
	int i;

	i = 1;
	fd = validate_input(argc, argv);
	valid_char = read_file(fd, 0, 0);
	if (valid_char != NULL)
	{
		int i;

		i = 0;
		while (valid_char[i])
			i++;
		algorithm(valid_char, i);
	}
	else
		ft_putstr("error\n");
	i++;
	return (0);
}
