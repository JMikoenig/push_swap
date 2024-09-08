NAME = push_swap

SRCS =	array_utils.c			\
		checks.c				\
		initialize.c			\
		input_parsing.c			\
		input_validation.c		\
		test_utils.c			\
		main.c					\
		push.c					\
		print_command.c			\
		rotate.c				\
		rev_rotate.c			\
		set_nodes.c				\
		sort_three.c			\
		stack_sorter.c			\
		str_utils.c				\
		swap.c					\
		utils.c					\

OBJS := ${SRCS:.c=.o}

HEADER = push_swap.h

FLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS):	$(SRCS)
	cc -c $(FLAGS) $(SRCS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all