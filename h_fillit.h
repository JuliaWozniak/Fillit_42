#ifndef H_FILLIT_H
# define H_FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>


typedef struct s_tetr
{
	struct s_tetr *n_t; // next
	struct s_tetr *pr_t; // previous
	int wid; // width
	char *fig; // trimmed string
	int s_p; // starting point
	int wid_k; 
}				t_tetr;

size_t		ft_strlen(const char *str);
char	*ft_strncpy(char *dest, const char *src, size_t num);
char	*ft_strchr(const char *str, int c);
char	*ft_strtrim(char const *s);
int		first_check(char *s);
int		second_check(char *arr, int row, int j);
void	create_ar(char *s, char *arr, int number);
int		validate_input(int argc, char **argv);
void algorithm(char **valid, int number);
void add_figure(char *fig, char *square, int s_p);
t_tetr *prepare_list(char **standard, int side);
int		ft_strequ(char const *s1, char const *s2);
t_tetr *change_list(char **standard, int side, t_tetr *list);




# endif