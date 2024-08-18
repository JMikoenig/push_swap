#include "push_swap.h"

void    print_command(char *str)
{
    while (*str)
        write(1, &str, 1);
    write(1, "\n", 1);
}