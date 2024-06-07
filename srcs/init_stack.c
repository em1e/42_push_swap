/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 09:42:05 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/07 10:28:23 by vkettune         ###   ########.fr       */
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

int	check_limit(t_stack *a, t_stack current_b, int stack, long limit)
{
	if ((current_b.nbr < a->nbr
			&& current_b.nbr > limit && stack == 'a')
		|| (current_b.nbr > a->nbr
			&& current_b.nbr < limit && stack == 'b'))
		return (1);
	return (0);
}

void	set_target(t_stack *a, t_stack *b, int stack, long limit)
{
	t_stack	*current_b;
	t_stack	*target_node;

	while (a)
	{
		if (stack == 'a')
			limit = LONG_MIN;
		else if (stack == 'b')
			limit = LONG_MAX;
		current_b = b;
		while (current_b)
		{
			if (check_limit(a, *current_b, stack, limit))
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

void	init_a(t_stack *a, t_stack *b)
{
	long	limit;

	limit = LONG_MIN;
	set_current_index(a, b);
	set_target(a, b, 'a', limit);
	cost_analysis(a, b);
	set_cheapest(a);
}

void	init_b(t_stack *a, t_stack *b)
{
	long	limit;

	limit = LONG_MAX;
	set_current_index(a, b);
	set_target(a, b, 'b', limit);
}

void	init_fill_a(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	if (!ft_isdigit(argv[i][0]) && argv[i][0] != '-' && argv[i][0] != '+')
		i++;
	while (argv[i])
	{
		if (check_syntax(argv[i]))
			error();
		n = ft_atol(argv[i]);
		if (n > LONG_MAX || n < LONG_MIN)
			free_errors(a);
		if (check_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}
