/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 09:32:11 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/07 09:46:27 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_syntax(char *n)
{
	if (!(*n == '+' || *n == '-'
			|| (*n >= '0' && *n <= '9')))
		return (1);
	if ((*n == '+' || *n == '-')
		&& !(n[1] >= '0' && n[1] <= '9'))
		return (1);
	while (*++n)
	{
		if (!(*n >= '0' && *n <= '9'))
			return (1);
	}
	return (0);
}

int	check_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	free_errors(t_stack **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
