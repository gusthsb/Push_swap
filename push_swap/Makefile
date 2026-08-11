NAME = push_swap

SRC = main.c flags.c parsing.c def_index.c disorder.c \
      lst_utils.c push.c reverse.c rotate.c \
      simple_sort.c simple_sort_utils.c swap.c \
      utils2.c verification_utils.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = .

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(PRINTF_LIB) $(NAME)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re