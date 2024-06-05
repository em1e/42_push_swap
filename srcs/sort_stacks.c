#include "push_swap.h"

void	sort_stacks(t_stack **a, t_stack **b) //Define a function that sorts stack `a` if it has more than 3 nodes
{
	int	len_a; 

	len_a = stack_len(*a);
	if (len_a-- > 3 && !is_sorted(*a)) //If stack `a` has more than three nodes and aren't sorted
		px(b, a, 'b');
	if (len_a-- > 3 && !is_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
		px(b, a, 'b');
	print_stack(a, 'a'); // for testing
	print_stack(b, 'b'); // for testing
	while (len_a-- > 3 && !is_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
	{
		init(*a, *b); //Iniate all nodes from both stacks
		move_a_to_b(a, b); //Move the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
		print_stack(a, 'a'); // for testing
		print_stack(b, 'b'); // for testing
	}
	sort_three(a);
	print_stack(a, 'a'); // for testing
	print_stack(b, 'b'); // for testing
	while (*b) //Until the end of stack `b` is reached
	{
		init(*b, *a); //Initiate all nodes from both stacks
		move_b_to_a(a, b); //Move all `b` nodes back to a sorted stack `a`
		print_stack(a, 'a'); // for testing
		print_stack(b, 'b'); // for testing
	}
	print_stack(a, 'a'); // for testing
	print_stack(b, 'b'); // for testing
	current_index(*a); //Refresh the current position of stack `a`
	print_stack(a, 'a'); // for testing
	print_stack(b, 'b'); // for testing
	min_on_top(a); //Ensure smallest number is on top
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
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}

void	move_a_to_b(t_stack **a, t_stack **b) //Define a function that prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`, until there are three nodes left in `a`
{
	t_stack	*cheapest_node; //To store the pointer to the cheapest `a` node

	cheapest_node = get_cheapest(*a); 
	if (cheapest_node->above_median 
		&& cheapest_node->target_node->above_median) //If both the cheapest `a` node and its target `b` node are above the median
		rr(a, b);
	else if (!(cheapest_node->above_median) 
		&& !(cheapest_node->target_node->above_median)) //If both the cheapest `a` node and its target `b` node are below the median
		rrr(a, b); //`rev_rotate_both` will execute if neither nodes are at the top
	// prep_for_push(a, cheapest_node, 'a'); //Ensure the cheapest nodes is at the top, ready for pushing
	// prep_for_push(b, cheapest_node->target_node, 'b'); //Ensure the target node is at the top, ready for pushing
	px(b, a, 'b');
}

void	move_b_to_a(t_stack **a, t_stack **b) //Define a function that prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a` 
{
	// prep_for_push(a, (*b)->target_node, 'a'); //Ensure `b`'s target `a` node is on top of the stack
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