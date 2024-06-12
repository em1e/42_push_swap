/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:04:23 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/10 15:34:24 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ')
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

void	insert_node(t_stack **stack, int nbr)
{
	t_stack	*new_node;
	t_stack	*tmp;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->nbr = nbr;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

void	set_current_index(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
}

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
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
