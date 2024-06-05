#include "push_swap.h"

void	rx(t_stack **x, int stack)
{
	t_stack	*last;

	if (!*x || !(*x)->next)
		return ;
	last = find_last(*x);
	last->next = *x;
	*x = (*x)->next;
	(*x)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
	if (stack == 'a' || stack == 'b')
		ft_printf("r%c\n", stack);
}

void	rr(t_stack **a, t_stack **b)
{
	rx(a, 'x');
	rx(b, 'x');
	ft_printf("rr\n");
}

void	rrx(t_stack **x, int stack)
{
	t_stack	*tmp;

	if (*x == 0 || (*x)->next == 0)
		return ;
	tmp = *x;
	while (tmp->next->next != 0)
		tmp = tmp->next;
	tmp->next->next = *x;
	*x = tmp->next;
	tmp->next = 0;
	if (stack == 'a' || stack == 'b')
		ft_printf("rr%c\n", stack);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrx(a, 'x');
	rrx(b, 'x');
	ft_printf("rrr\n");
}
