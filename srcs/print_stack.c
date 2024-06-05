/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:14:21 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/05 14:12:54 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack **x, int stack)
{
	t_stack	*temp;

	(void)stack;
	if (*x == 0)
		return ;
	temp = *x;
	ft_printf("- - - - - stack %c - - - - - \n", stack);
	while (temp != NULL)
	{
		ft_printf("%d ", temp->nbr);
		temp = temp->next;
	}
	ft_printf("\n- - - - - - - - - - - - - - \n");
}

// print_stack(a, 'a'); // for testing
// print_stack(b, 'b'); // for testing