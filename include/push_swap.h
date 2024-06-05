/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 09:42:05 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/05 15:50:15 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include <limits.h>

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
char		**free_split(char **split);
int			check_syntax(char *n);
int			error_duplicate(t_stack *a, int n);
void		free_errors(t_stack **a);
int			error(void);
void		free_stack(t_stack **stack);

// find_stack.c
t_stack		*find_max(t_stack *stack);
t_stack		*find_min(t_stack *stack);
t_stack		*find_last(t_stack *stack);
int			stack_len(t_stack *stack);

// init_stack.c
t_stack		*find_target_node(t_stack *y, int stack);
void		set_target(t_stack *x, t_stack *y, int stack);
void		init_a(t_stack *a, t_stack *b);
void		init_b(t_stack *a, t_stack *b);
void		init_fill_a(t_stack **a, char **argv);

// is_sorted.c
bool		is_sorted(t_stack *stack);

// main.c
void		print_stack(t_stack **x, int stack);
int			main(int argc, char **argv);

// push_cost.c
t_stack		*get_cheapest(t_stack *stack);
void		set_cheapest(t_stack *stack);
void		current_index(t_stack *stack);
void		cost_analysis(t_stack *x, t_stack *y);

// rotate.c
void		rx(t_stack **x, int stack);
void		rr(t_stack **a, t_stack **b);
void		rrx(t_stack **x, int stack);
void		rrr(t_stack **a, t_stack **b);

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
void		append_node(t_stack **stack, int n);

#endif