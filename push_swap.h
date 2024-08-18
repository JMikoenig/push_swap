

typedef struct node
{
	int			value;
	int			pos;
	bool		above_median;
	struct node	*target;
	struct node	*next;
	struct node	*prev;
}				Node;

// split.c
char    	**ft_split(char *str, char separator);
static char *get_word(char *str, char separator);
static int  count_words(char *str, char separator);

// utils.c
void    print_command(char *str);

// === OPERATIONS ===

void    push_a(void);
void    push_b(void);

