NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
HDRS = lib.h

SRCS = main.c utils_opr.c utils.c utils2.c \
		sort.c sort_hard.c swp.c swp2.c \
		parsing.c push_swap_utils_2.c push_swap_utils.c main_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(OBJS): $(HDRS)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

clean:
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all