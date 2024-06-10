/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 06:54:01 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/10 13:26:54 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

void	helper(char **argv, char **array, t_stack **a)
{
	if (array)
		init_fill_a(a, array);
	else
		init_fill_a(a, argv);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**array;

	a = NULL;
	b = NULL;
	array = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && !argv[1][0])
		error();
	if (argc == 2 && argv[1][1])
		array = split(argv[1], ' ');
	helper(argv, array, &a);
	if (!is_sorted(a))
	{
		if (stack_len(a) <= 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_array(array);
	free_stack(&a);
	return (0);
}
