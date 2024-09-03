#include "push_swap.h"
#include <unistd.h>


static void	print_something(const char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void print_command(const int cmd_code)
{
	char  *commands[13]; 
	commands[0] = "";
	commands[1] = "";
	commands[2] = "pa";
	commands[3] = "pb";
	commands[4] = "sa";
	commands[5] = "sb";
	commands[6] = "ss";
	commands[7] = "ra";
	commands[8] = "rb";
	commands[9] = "rr";
	commands[10] = "rra";
	commands[11] = "rrb";
	commands[12] = "rrr";

	print_something(commands[cmd_code]);
} 

