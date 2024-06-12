/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:46:19 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/12 10:08:32 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_target_node(t_stack *b, int stack)
{
	if (stack == 'a')
		return (find_biggest(b));
	else if (stack == 'b')
		return (find_smallest(b));
	return (NULL);
}

int	check_b(t_stack *a, t_stack current_b, int stack, long limit)
{
	if ((current_b.nbr < a->nbr
			&& current_b.nbr > limit && stack == 'a')
		|| (current_b.nbr > a->nbr
			&& current_b.nbr < limit && stack == 'b'))
		return (1);
	return (0);
}

long	assign_limit(long limit, int stack)
{
	if (stack == 'a')
		limit = LONG_MIN;
	else if (stack == 'b')
		limit = LONG_MAX;
	return (limit);
}

void	set_target(t_stack *a, t_stack *b, int stack, long limit)
{
	t_stack	*current_b;
	t_stack	*target_node;

	while (a)
	{
		limit = assign_limit(limit, stack);
		current_b = b;
		while (current_b)
		{
			if (check_b(a, *current_b, stack, limit))
			{
				limit = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if ((limit == LONG_MAX && stack == 'b')
			|| (limit == LONG_MIN && stack == 'a'))
			a->target_node = find_target_node(b, stack);
		else
			a->target_node = target_node;
		a = a->next;
	}
}
