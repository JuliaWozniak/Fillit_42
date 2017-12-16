CC = gcc
NAME = fillit

FILES = lib_functions.c \
		validation.c \
		main.c \
		small.c \
		preparation.c \
		algorithm.c \
		helpers.c

OBJS = $(FILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
all: $(FILES) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean all