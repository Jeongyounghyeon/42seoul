#include <stdio.h>
#include "push_swap.h"

int	push_swap(char **argv)
{
	t_stack	*stack_a;
	
	stack_a = make_stack(argv);
	if (!stack_a)
		return (ERROR);

	// start_test
	printf("--------------------------------------------------<Input Test>--------------------------------------------------\n");
	printf("Input:\n")
	while (emptystack(stack_a))
		printf(" %d," pop_bottom(stack_a));
	printf("\n");
	printf("-----------------------------------------------<Input Test Close>-----------------------------------------------\n");
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