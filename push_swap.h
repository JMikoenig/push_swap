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

// split.c
int		str_separate(char *srcstr, char sep, char ***output);

// utils.c
void	print_command(char *str);
t_node	*create_node(int value);
int		*arr_atoi(char **tokens, int size);

// checks.c
int		check_overflow(long n);
int		check_syntax(const char *n);
int		has_repetitions(const int *arrayToSort, const int size);

// str_utils.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

//test_utils.c
void	printList(t_node *head, int size);
void	printStrList(char **list, int size);
void	printIntList(int *arr, int size);

//ft_calloc.c
void	*ft_calloc(size_t count, size_t size);

// === OPERATIONS ===

void	push(t_node **head_src, t_node **head_dst);
void	rotate(t_node **head);
void	rev_rotate(t_node **head);
void	double_rotate(t_node **head_a, t_node **head_b);
void	double_rev_rotate(t_node **head_a, t_node **head_b);
int		initialize(t_node **head, const int *arr, const int size);
