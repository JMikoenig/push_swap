#define STACK_A 'a'
#define STACK_B 'b'
#include <limits.h>
#include <stddef.h>

typedef struct s_node
{
	int				value;
	int				pos;
	int				above_median;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// input_parsing.c
int parse_input_array(int argc, char** argv, int** output_int_arr);

// utils.c
void	print_command(const char *str);
t_node	*create_node(int value);
int		*arr_atoi(char **tokens, int size);

// checks.c
int		check_overflow(long n);
int		check_syntax(const char *n);

// str_utils.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

// test_utils.c
void	printList(t_node *head, int size);
void	printStrList(char **list, int size);
void	printIntList(int *arr, int size);

// input_validation.c
int enough_arguments(int argc, char** argv);
int	has_duplicates(const int *int_arr, const int size);
int		is_sorted(const int *arr, const int size);

// stack_sorter.c
int sort(const int *input_arr, int size);

// === OPERATIONS ===

void	push(t_node **head_src, t_node **head_dst);
void	rotate(t_node **head);
void	rev_rotate(t_node **head);
void	double_rotate(t_node **head_a, t_node **head_b);
void	double_rev_rotate(t_node **head_a, t_node **head_b);
int		initialize(t_node **head, const int *arr, const int size);
