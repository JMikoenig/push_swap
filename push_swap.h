#include <limits.h>
#define STACK_A 'a'
#define STACK_B 'b'
#include <stddef.h>


typedef struct node
{
	int			value;
	int			pos;
	int		above_median;
	struct node	*target;
	struct node	*next;
	struct node	*prev;
}				Node;

// split.c
int str_separate(char *srcstr, char sep, char ***output);

// utils.c
void    print_command(char *str);
Node* create_node(int value);
int *arr_atoi(char **tokens, int size);

// checks.c
int check_overflow(long n);
int check_syntax(const char *n);

// str_utils.c
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

//test_utils.c
void printList(Node *head, int size);
void printStrList(char **list, int size);
void printIntList(int *arr, int size);


// === OPERATIONS ===

void    push_a(void);
void    push_b(void);
void	rotate(Node **head);
void	rev_rotate(Node **head);
void	double_rotate(Node **head_a, Node **head_b);
void	double_rev_rotate(Node **head_a,  Node **head_b);
int initialize(Node* head, int *arr, int *size);

