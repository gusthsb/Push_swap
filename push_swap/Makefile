NAME = push_swap

SRC = main.c flags.c parsing.c def_index.c disorder.c \
      lst_utils.c push.c reverse.c rotate.c \
      simple_sort.c simple_sort_utils.c swap.c \
      utils2.c verification_utils.c bench.c bench_utils.c \
	  medium_sort.c complex_sort.c adaptive_sort.c print.c \
	  medium_utils.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = .

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