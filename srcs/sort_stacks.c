#include "push_swap.h"

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a; 

	len_a = stack_len(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		px(b, a, 'b');
	if (len_a-- > 3 && !is_sorted(*a))
		px(b, a, 'b');
	print_stack(a, 'a'); // for testing
	print_stack(b, 'b'); // for testing
	while (len_a-- > 3 && !is_sorted(*a))
	{
		init_a(*a, *b);
		move_a_to_b(a, b);
		print_stack(a, 'a'); // for testing
		print_stack(b, 'b'); // for testing
	}
	sort_three(a);
	print_stack(a, 'a'); // for testing
	print_stack(b, 'b'); // for testing
	while (*b)
	{
		init_b(*b, *a);
		move_b_to_a(a, b);
		print_stack(a, 'a'); // for testing
		print_stack(b, 'b'); // for testing
	}
	current_index(*a);
	print_stack(a, 'a'); // for testing
	print_stack(b, 'b'); // for testing
	min_on_top(a);
	ft_printf("final!!\n");
	print_stack(a, 'a'); // for testing
	print_stack(b, 'b'); // for testing
}

void	min_on_top(t_stack **a) //Define a function that moves the smallest number to the top
{
	while ((*a)->nbr != find_min(*a)->nbr) //As long as the smallest number is not at the top
	{
		if (find_min(*a)->above_median) //Rotate or reverse rotate according to the position of the node on the median
			rx(a, 'a');
		else
			rrx(a, 'a');
	}
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median)
				rx(stack, 'a');
			else
				rrx(stack, 'a');
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				rx(stack, 'b');
			else
				rrx(stack, 'b');
		}	
	}
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a); 
	if (cheapest_node->above_median 
		&& cheapest_node->target_node->above_median)
		{
			// rr(a, b);
			while (*b != cheapest_node->target_node && *a != cheapest_node)
				rr(a, b);
			// current_index(*a);
			// current_index(*b);
		}
	else if (!(cheapest_node->above_median) 
		&& !(cheapest_node->target_node->above_median))
		{
			// rrr(a, b);
			while (*b != cheapest_node->target_node && *a != cheapest_node)
				rrr(a, b);
			// current_index(*a);
			// current_index(*b);
		}
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	px(b, a, 'b');
}

void	move_b_to_a(t_stack **a, t_stack **b) //Define a function that prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a` 
{
	prep_for_push(a, (*b)->target_node, 'a'); //Ensure `b`'s target `a` node is on top of the stack
	px(a, b, 'a');
}

void	sort_three(t_stack **a) 
{
	t_stack	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		rx(a, 'a');
	else if ((*a)->next == biggest_node)
		rrx(a, 'a');
	if ((*a)->nbr > (*a)->next->nbr)
		sx(a, 'a');
}