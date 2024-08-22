#include <limits.h>
#define STACK_A 'a'
#define STACK_B 'b'


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
// int	ft_split(char *str, char separator, char ***tokens);
int str_separate(char *srcstr, char sep, char ***output);

// utils.c
void printStrList(char **list, int size);
void printIntList(int *arr, int size);
int *arr_atoi(char **tokens, int size);

// checks.c
int check_overflow(long n);
int check_syntax(const char *n);


// === OPERATIONS ===

void    push_a(void);
void    push_b(void);
void	rotate(Node **head);
void	rev_rotate(Node **head);
void	double_rotate(Node **head_a, Node **head_b);
void	double_rev_rotate(Node **head_a,  Node **head_b);
void    print_command(char *str);
void printList(Node *head, int size);
Node* createNode(int value);
int initialize(Node* head, int *arr, int *size);

