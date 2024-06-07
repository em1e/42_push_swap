/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:54:01 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/07 09:43:28 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_biggest(t_stack *stack)
{
	long	biggest;
	t_stack	*node;

	if (!stack)
		return (NULL);
	biggest = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > biggest)
		{
			biggest = stack->nbr;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

t_stack	*find_smallest(t_stack *stack)
{
	long	min;
	t_stack	*node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
