#include <stdio.h>
#include "../push_swap.h"

int	push_swap(char **argv)
{
	t_stack	*stack_a;
	int i;

	stack_a = make_stack(argv);
	if (!stack_a)
		return (ERROR);

	// start_stest
	printf("--------------------------------------------------<Input Test>--------------------------------------------------\n");
	printf("Input:\n");
	while (!emptystack(stack_a))
		printf(" %d,", pop_bottom(stack_a));
	printf("\n");
	free (stack_a);
	printf("-----------------------------------------------<Input Test Close>-----------------------------------------------\n");
	stack_a = make_stack(argv);
	printf("Stack:\n");
	while (!emptystack(stack_a))
		printf(" %d,", pop(stack_a));
	printf("\n");
	free (stack_a);
	printf("-------------------------------------------------<commend Test>-------------------------------------------------\n");
	stack_a = make_stack(argv);
	printf("sa test:\n");
	sa(stack_a);
	while (!emptystack(stack_a))
		printf(" %d,", pop(stack_a));
	printf("\n");
	free (stack_a);
	stack_a = make_stack(argv);
	printf("ra test:\n");
	ra(stack_a);
	while (!emptystack(stack_a))
		printf(" %d,", pop(stack_a));
	printf("\n");
	free (stack_a);
	stack_a = make_stack(argv);
	printf("rra test:\n");
	rra(stack_a);
	while (!emptystack(stack_a))
		printf(" %d,", pop(stack_a));
	printf("\n");
	free (stack_a);
	printf("----------------------------------------------<commend Test Close>----------------------------------------------\n");
	
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