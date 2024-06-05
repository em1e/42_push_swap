/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 06:54:01 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/05 18:05:23 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		arg_str;
	// int		i;

	a = NULL;
	b = NULL;
	arg_str = 0;
	// i = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (error());
	// ft_printf("1 test\n");
	// if (argv[1])
	// 	ft_printf("argv[%d]: %s\n", 1, argv[1]);
	if (argc == 2 && argv[1][1])
		argv = split(argv[1], ' ');
	if (argc == 2 && argv[1][1])
		arg_str = 1;
	// while (argv[i] != NULL)
	// {
	// 	ft_printf("main argv[%d]: %s\n", i, argv[i]);
	// 	i++;
	// }
	// ft_printf("3 test\n");
	init_fill_a(&a, argv);
	if (arg_str == 1)
		free_split(argv);
	if (!is_sorted(a))
	{
		if (stack_len(a) <= 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
