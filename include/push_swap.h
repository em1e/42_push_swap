/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 09:42:05 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/10 13:28:05 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include <limits.h>

# define MY_MAX_INT 2147483647
# define MY_MIN_INT -2147483648

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// error_handling.c
void		free_array(char **array);
void		free_stack(t_stack **stack);
void		free_errors(t_stack **a);
void		error(void);

// find.c
t_stack		*find_biggest(t_stack *stack);
t_stack		*find_smallest(t_stack *stack);
t_stack		*find_last(t_stack *stack);

// init_stack.c
void		init_a(t_stack *a, t_stack *b);
void		init_b(t_stack *a, t_stack *b);
int			check_syntax(char *n);
int			check_duplicate(t_stack *a, int n);
void		init_fill_a(t_stack **a, char **argv);

// is_sorted.c
bool		is_sorted(t_stack *stack);

// main.c
int			stack_len(t_stack *stack);
int			main(int argc, char **argv);

// push_cost.c
t_stack		*get_cheapest(t_stack *stack);
void		set_cheapest(t_stack *stack);
void		cost_analysis(t_stack *x, t_stack *y);

// rotate.c
void		rx(t_stack **x, int stack);
void		rr(t_stack **a, t_stack **b);
void		rrx(t_stack **x, int stack);
void		rrr(t_stack **a, t_stack **b);

// set_target.c
t_stack		*find_target_node(t_stack *b, int stack);
int			check_limit(t_stack *a, t_stack current_b, int stack, long limit);
long		assign_limit(long limit, int stack);
void		set_target(t_stack *a, t_stack *b, int stack, long limit);

// sort_stacks.c
void		prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void		move_a_to_b(t_stack **a, t_stack **b);
void		move_b_to_a(t_stack **a, t_stack **b);
void		min_on_top(t_stack **a);
void		sort_stacks(t_stack **a, t_stack **b);

// sort_three.c
void		sort_three(t_stack **a);

// split.c
int			count_words(char *s, char c);
char		*next_word(char *s, char c);
char		**split(char *s, char c);

// swap.c
void		px(t_stack **x, t_stack **y, int stack);
void		sx(t_stack **x, int stack);
void		ss(t_stack **a, t_stack **b);

// utils.c
long		ft_atol(const char *s);
void		insert_node(t_stack **stack, int n);
void		set_current_index(t_stack *a, t_stack *b);
void		current_index(t_stack *stack);

// !! testing !!
// void		print_stack(t_stack **x, int stack);
// print_stack(&a, 'a');

#endif