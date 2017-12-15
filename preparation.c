#include "h_fillit.h"

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

char *prepare_str(char *str, int side)
{
	int i;
	int j;
	char *res;
	int k;

	i = 0;
	j = 0;
	if (ft_strlen(str) == 4)
		return (str);
	if ((res = (char *)malloc(sizeof(char) * (side * 4))) == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] != '.')
			res[j++] = str[i++];
		else
		{
			k = find_next(&str[i + 1]);
			i = i + k;
			k = switch_k(k, side);
			while (k--)
				res[j++] = '.';
		}	
	}
	res[j] = '\0';
	return (res);
}

t_tetr *create_elem(char *fig, int width, int k)
{
	t_tetr *temp;

	temp = (t_tetr *)malloc(sizeof(t_tetr));
	if (temp == NULL)
		return (NULL);
	temp->n_t = NULL;
	temp->pr_t = NULL;
	temp->s_p = -1;
	temp->fig = fig;
	temp->wid = width;
	temp->wid_k = k;
	temp->tries = 0;
	return (temp);
}

int get_width(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] == '.')
		i++;
	while (((i + 1) % 4) != 0)
	{
		if (str[i++] != '.')
			j++;
	}
	if (str[i++] != '.')
			j++;
	return (j);
}

int wid_k(char *str)
{
	char temp[16];
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] != '.')
			temp[i] = '#';
		else
			temp[i] = '.';
		i++;
	}
	temp[i] = '\0';
	if (ft_strequ(temp, "#...###") == 1)
		return (3);
	else if (ft_strequ(temp, "#...##...#") == 1)
		return (2);
	else if (ft_strequ(temp, "##...##") == 1)
		return (3);
	else if (ft_strequ(temp, "#..###") == 1)
		return (2);
	else
		return (0);
}
t_tetr *change_list(char **standard, int side, t_tetr *list)
{
	char *str;
	int i;

	i = 0;
	while (list->n_t)
	{
		str = ft_strtrim(standard[i]);
		str = prepare_str(str, side);
		free(list->fig);
		list->fig = str;
		list->s_p = -1;
		list = list->n_t;
		i++;
	}
		str = prepare_str(standard[i], side);
		free(list->fig);
		list->fig = str; 

	while (list->pr_t)
		list = list->pr_t;
	return (list);
}


t_tetr *prepare_list(char **standard, int side)
{
	int i;
	t_tetr *current;
	char *str;
	int width;
	int k;

	i = 0;
	while (standard[i])
	{		
		str = ft_strtrim(standard[i]);
		k = wid_k(str);
		str = prepare_str(str, side);
		width = get_width(standard[i]);
		if (i++ != 0)
		{
			if ((current->n_t = create_elem(str, width, k)) == NULL)
			return (NULL);
		current->n_t->pr_t = current;
		current = current->n_t;
		}
		else
		{
			if ((current = create_elem(str, width, k)) == NULL)
				return (NULL);
		}
	}
	while (current->pr_t)
		current = current->pr_t;
	return (current);
}

