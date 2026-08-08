NAME = push_swap
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = .
SRC = main.c flags.c parsing.c def_index.c disorder.c \
			  lst_utils.c push.c reverse.c rotate.c \
			  simple_sort.c simple_sort_utils.c swap.c \
			  utils2.c verification_utils.c
 
all: $(NAME)
 
$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o: %.c
		$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
 
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all
 
.PHONY: all clean fclean re