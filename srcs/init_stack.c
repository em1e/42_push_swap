
#include "push_swap.h"

long	ft_atol(const char *s) //Define a function that converts every string into a long value
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

void	cost_analysis(t_stack *x, t_stack *y)
{
	int	len_x;
	int	len_y;

	len_x = stack_len(x);
	len_y = stack_len(y);
	while (x)
	{
		x->push_cost = x->index;
		if (!(x->above_median))
			x->push_cost = len_x - (x->index);
		if (x->target_node->above_median)
			x->push_cost += x->target_node->index;
		else
			x->push_cost += len_y - (x->target_node->index);
		x = x->next;
	}
}

void	append_node(t_stack **stack, int n) //Define a function that searches for the last node to append to the linked list
{
	t_stack	*node; //To store a pointer to the new node to be created with the value `n`
	t_stack	*last_node; //To store a pointer to the current last node of the stack

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack)); //Allocate memory for the new node
	if (!node)
		return ;
	node->next = NULL; //Set the next pointer of the new node to NULL because it will be the last node in the list
	node->nbr = n; //Set the `next` data of of the new node to `n` value
	if (!(*stack)) //Check if the stack is empty or currently pointing to NULL, indicating a first node needs to be found
	{
		*stack = node; //If empty, update the pointer *stack to point to the node, effectively making it the new head of the linked list
		node->prev = NULL; //Set the head node's previous pointer to NULL as it's the first node
	}
	else //If the stack is not empty, it means there are existing nodes in the linked list
	{
		last_node = find_last(*stack); //In which case, find the last node
		last_node->next = node; //Append the new node to the last node
		node->prev = last_node; //Update the previous pointer of the new node and complete the appending
	}
}

void	set_target(t_stack *x, t_stack *y)
{
	t_stack	*current_y;
	t_stack	*target_node;
	long			best_match_index;

	while (x)
	{
		best_match_index = LONG_MIN;
		current_y = y;
		while (current_y)
		{
			if (current_y->nbr < x->nbr 
				&& current_y->nbr > best_match_index)
			{
				best_match_index = current_y->nbr;
				target_node = current_y;
			}
			current_y = current_y->next;
		}
		if (best_match_index == LONG_MIN)
			x->target_node = find_max(y);
		else
			x->target_node = target_node;
		x = x->next;
	}
}

void	init(t_stack *x, t_stack *y)
{
	current_index(x);
	current_index(y);
	set_target(x, y);
	cost_analysis(x, y);
	set_cheapest(x);
}

void	init_stack_a(t_stack **a, char **argv) //Define a function that initiates stack `a` by handling any errors and appending required nodes to complete a stack
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		// if (error_syntax(argv[i]))
		// 	free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN) //Check for overflow
			free_errors(a);
		// if (error_duplicate(*a, (int)n))
		// 	free_errors(a); 
		append_node(a, (int)n); //If no errors, append the node to the linked list by, taking a pointer to stack `a`, create a new node and assign `n` to that new node
		i++;
	}
}

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	set_cheapest(t_stack *stack)
{
	long			cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
