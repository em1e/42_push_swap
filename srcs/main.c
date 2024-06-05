#include "push_swap.h"

void print_stack(t_stack **x, int stack) // for testing
{
	t_stack	*temp;

	if (*x == 0)
		return ;
	temp = *x;
	ft_printf("- - - - - stack %c - - - - - \n", stack);
	while (temp != NULL)
	{
		ft_printf("%d ", temp->nbr);
		temp = temp->next;
	}
	ft_printf("\n- - - - - - - - - - - - - - \n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		argv = split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (!is_sorted(a))
	{
		ft_printf("pls sort this!\n"); // remove
		print_stack(&a, 'a'); // for testing
		if (stack_len(a) <= 3)
		{
			sort_three(&a);
			print_stack(&a, 'a'); // for testing
		}
		else 
			sort_stacks(&a, &b);
	}
	print_stack(&a, 'a'); // for testing
	ft_printf("All sorted!\n"); // remove
	free_stack(&a);
	return (0);
}

