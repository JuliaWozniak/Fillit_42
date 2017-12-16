#ifndef H_FILLIT_H
# define H_FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct 	s_tetr
{
	struct s_tetr *n_t;
	struct s_tetr *pr_t;
	int wid;
	char 	*fig;
	int 	s_p;
	int 	wid_k;
	int 	tries;
}				t_tetr;

size_t		ft_strlen(const char *str);
char		*ft_strncpy(char *dest, const char *src, size_t num);
char		*ft_strchr(const char *str, int c);
char		*ft_strtrim(char const *s);
void		ft_putstr(char const *s);
int			ft_strequ(char const *s1, char const *s2);


int			first_check(char *s);
int			second_check(char *arr, int row, int j);
void		create_ar(char *s, char *arr, int number);
int			validate_input(int argc, char **argv);
void 		algorithm(char **valid, int number);
void 		add_figure(char *fig, char *square, int s_p);
t_tetr 		*prepare_list(char **standard, int side);
t_tetr 		*change_list(char **standard, int side, t_tetr *list);
int 		print_one(char *single);
int 		fit_in_square(int side, t_tetr *list);
void 		print_result(char *sqr, int side);
void 		clear(char *sqr);
int 		make_square(int number);
char		*create_sqr(int side);
int			try(int side, t_tetr *list, char *sqr, int sp);
int find_next(char *str);
int switch_k(int k, int side);

# endif