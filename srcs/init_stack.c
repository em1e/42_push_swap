/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 09:42:05 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/12 10:30:41 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_syntax(char *nbr)
{
	if (!(*nbr == '+' || *nbr == '-'
			|| (*nbr >= '0' && *nbr <= '9')))
		return (1);
	if ((*nbr == '+' || *nbr == '-')
		&& !(nbr[1] >= '0' && nbr[1] <= '9'))
		return (1);
	while (*++nbr)
	{
		if (!(*nbr >= '0' && *nbr <= '9'))
			return (1);
	}
	return (0);
}

int	check_duplicate(t_stack *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	init_fill_a(t_stack **a, char **array)
{
	long	n;
	int		i;

	i = 0;
	if (ft_strncmp(array[i], "./push_swap", 11) == 0)
		i++;
	if (!ft_isdigit(array[i][0]) && array[i][0] != '-' && array[i][0] != '+')
		i++;
	if (array[i] == NULL)
		error();
	while (array[i])
	{
		if (check_syntax(array[i]))
			error();
		n = ft_atol(array[i]);
		if (n > MY_MAX_INT || n < MY_MIN_INT)
			free_errors(a);
		if (check_duplicate(*a, (int)n))
			free_errors(a);
		insert_node(a, (int)n);
		i++;
	}
}
