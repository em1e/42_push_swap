/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 09:42:05 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/05 18:04:39 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_target_node(t_stack *y, int stack)
{
	if (stack == 'a')
		return (find_min(y));
	else if (stack == 'b')
		return (find_max(y));
	return (NULL);
}

void	set_target(t_stack *x, t_stack *y, int stack)
{
	t_stack	*current_y;
	t_stack	*target_node;
	long	best_match_index;

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
			x->target_node = find_target_node(y, stack);
		else
			x->target_node = target_node;
		x = x->next;
	}
}

void	init_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target(a, b, 'a');
	cost_analysis(a, b);
	set_cheapest(a);
}

void	init_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target(a, b, 'b');
}

void	init_fill_a(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	// ft_printf("test\n");
	if (!ft_isdigit(argv[i][0]) && argv[i][0] != '-' && argv[i][0] != '+')
		i++;
	while (argv[i])
	{
		// ft_printf("init argv[%d]: %s\n", i, argv[i]);
		if (check_syntax(argv[i]))
			error();
		n = ft_atol(argv[i]);
		if (n > LONG_MAX || n < LONG_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}
