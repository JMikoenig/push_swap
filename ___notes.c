/* STRUCT */

typedef struct s_stack_node
{
	int					value;				// 
	int					current_position;	// 
	int					final_index;		// 
	int					push_price;			// 
	bool				above_median;		// 
	bool				cheapest;			// 
	struct s_stack_node	*target_node;		// 
	struct s_stack_node	*next;				// 
	struct s_stack_node	*prev;				// 
}				t_stack_node;				// 


/* MAIN */

