NAME = push_swap

SRCS =	array_utils.c			main.c				sort_three.c	\
		checks.c				push.c				stack_sorter.c	\
		initialize.c			print_command.c		str_utils.c		\
		input_parsing.c			rotate.c			swap.c			\
		input_validation.c		rev_rotate.c		utils.c			\
		logic.c					set_nodes.c							\
		test_utils.c												\

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