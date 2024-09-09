NAME = push_swap

SRCS =	checks.c				\
		initialize.c			\
		input_parsing.c			\
		input_validation.c		\
		main.c					\
		node_management.c		\
		push.c					\
		rotate.c				\
		rev_rotate.c			\
		sort_specific_sizes.c	\
		stack_sorter.c			\
		str_utils.c				\
		swap.c					\
		utils.c					\

OBJS := ${SRCS:.c=.o}

HEADER = push_swap.h

FLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	cc $(FLAGS) -g -o $(NAME) $(OBJS)

$(OBJS):	$(SRCS)
	cc -c $(FLAGS) $(SRCS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all