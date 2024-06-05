/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:09:01 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/05 10:16:56 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(t_stack **x, t_stack **y, int stack)
{
	t_stack	*tmp;

	if (*y == 0)
		return ;
	tmp = *y;
	*y = tmp->next;
	tmp->next = *x;
	*x = tmp;
	if (stack == 'a' || stack == 'b')
		ft_printf("p%c\n", stack);
}

void	sx(t_stack **x, int stack)
{
	t_stack	*tmp;

	if (*x == 0 || (*x)->next == 0)
		return ;
	tmp = *x;
	*x = tmp->next;
	tmp->next = tmp->next->next;
	(*x)->next = tmp;
	if (stack == 'a' || stack == 'b')
		ft_printf("s%c\n", stack);
}

void	ss(t_stack **a, t_stack **b)
{
	sx(a, 'x');
	sx(b, 'x');
	ft_printf("ss\n");
}
