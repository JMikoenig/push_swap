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
// char    	**ft_split(char *str, char separator);
// static char *get_word(char *str, char separator);
// static int  count_words(char *str, char separator);

// utils.c
// void    print_command(char *str);

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

