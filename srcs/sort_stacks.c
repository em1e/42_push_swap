/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 03:55:01 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/12 10:52:12 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				rx(stack, 'a');
			else
				rrx(stack, 'a');
		}
		else if (stack_name == 'b')
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
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median
		&& cheapest->target_node->above_median)
	{
		while (*b != cheapest->target_node && *a != cheapest)
			rr(a, b);
		set_current_index(*a, *b);
	}
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
	{
		while (*b != cheapest->target_node && *a != cheapest)
			rrr(a, b);
		set_current_index(*a, *b);
	}
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target_node, 'b');
	px(b, a, 'b');
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	px(a, b, 'a');
}

void	min_on_top(t_stack **a)
{
	t_stack	*smallest;

	smallest = find_smallest(*a);
	while ((*a)->nbr != smallest->nbr)
	{
		if (smallest->above_median)
			rx(a, 'a');
		else
			rrx(a, 'a');
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (len-- > 3 && !is_sorted(*a))
		px(b, a, 'b');
	if (len-- > 3 && !is_sorted(*a))
		px(b, a, 'b');
	while (len-- > 3 && !is_sorted(*a))
	{
		init_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_b(*b, *a);
		move_b_to_a(a, b);
	}
	min_on_top(a);
}
