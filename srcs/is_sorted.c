#include "push_swap.h"

bool	is_sorted(t_stack *stack) //Define a function that checks if the stack is sorted in ascending order
{
	if (!stack)
		return (1);
	while (stack->next) //Loop until the end of the stack is reached
	{
		if (stack->nbr > stack->next->nbr) //Check if the current value is larger than the next node's value, indicating it is out of sort
			return (false);
		stack = stack->next; //If not, move to the next node for processing
	}
	return (true);
}