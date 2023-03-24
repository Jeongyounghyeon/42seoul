#include <stdio.h>
#include "../push_swap.h"

int	push_swap(char **argv)
{
	t_stack	*stack_a;
	t_stack	stack_b;
	int i;
	
	stack_a = make_stack(argv);
	if (sort_stack(stack_a, &stack_b) == ERROR)
		return (ERROR);
	free (stack_a);	
	return (0);
}

int	main(int argc, char **argv)
{
	int	res;

	if (argc == 1)
		return (0);
	
	res = push_swap(argv + 1);
	if (res == ERROR)
		write(1, "Error\n", 6);
	return (0);
}