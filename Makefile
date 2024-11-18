NAME = push_swap
SORC = ./push_swap.c ./push_swap_utils.c ./push_swap_utils2.c ./coordinate_compression.c ./free.c ./sort_action.c \
		./sort_action_util.c ./debug.c ./search_insert_min_node.c ./search_insert_min_node_utils.c ./check_input.c \
		./check_input_utils.c ./search_min_count.c ./utils.c ./error.c
OBJS = $(SORC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -fno-omit-frame-pointer
# CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./libft -lft -L./ft_printf -lftprintf

all: lib printf $(NAME)

lib:
		$(MAKE) -C ./libft

printf:
		$(MAKE) -C ./ft_printf

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ 

clean:
		rm -f $(OBJS) $(BOJS)
		$(MAKE) -C ./libft clean
		$(MAKE) -C ./ft_printf clean

fclean:	clean
		rm -f $(NAME)
		$(MAKE) -C ./libft fclean
		$(MAKE) -C ./ft_printf fclean

re:	fclean all

.PHONY: all clean fclean re bonus