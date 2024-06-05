

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
#include <stdbool.h>
# include <limits.h>

// typedef struct s_stack
// {
// 	int				num;
// 	struct s_stack	*next;
// 	struct s_stack	*prev;
// }	t_stack;

typedef struct s_stack //A container of data enclosed in {} braces. `s_` for struct
{
	int					nbr; //The number to sort
	int					index; //The number's position in the stack
	int					push_cost; //How many commands in total
	bool				above_median; //Used to calculate `push_cost`
	bool				cheapest; //The node that is the cheapest to do commands
	struct s_stack	*target_node; //The target node of a node in the opposite stack
	struct s_stack	*next; //A pointer to the next node
	struct s_stack	*prev; //A pointer to the previous node
}	t_stack; //The "shortened name", "t_stack_node". `t_` for type

void print_stack(t_stack **x, int stack);

t_stack	*stack_from_str(char *str);
void	free_errors(t_stack **a);
char **split(char *s, char c);
void	init_stack_a(t_stack **a, char **argv);
bool	is_sorted(t_stack *stack);
t_stack	*find_last(t_stack *stack);
void	sort_three(t_stack **a);
void	sort_stacks(t_stack **a, t_stack **b);

int	stack_len(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);

t_stack	*get_cheapest(t_stack *stack);
void	set_cheapest(t_stack *stack);
void	init_stack_a(t_stack **a, char **argv);
void	init_a(t_stack *x, t_stack *y);
void	init_b(t_stack *a, t_stack *b);
void	current_index(t_stack *stack);

void	cost_analysis(t_stack *x, t_stack *y);
void	move_a_to_b(t_stack **a, t_stack **b);
void	set_target(t_stack *x, t_stack *y, int stack);

void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	min_on_top(t_stack **a);


t_stack	*make_stack(int len, char **strs);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stacknew(int n);

int		get_smallest(t_stack **stack_x);
int		get_largest(t_stack **stack_x);
int		get_shortest_dir(t_stack **stack_x, int i);
// int		is_sorted(t_stack **stack_a);
int		ft_stacksize(t_stack *stack);

void	free_all(t_stack **stack_a, t_stack **stack_b, t_list **commands);
int		error(char *msg);
void	free_stack(t_stack **stack);

void	tiny_sort(t_stack **stack_a, t_stack **stack_b, t_list **commands);
void	exec_command(t_stack **stack_a, t_stack **stack_b, char *command,
			t_list **commands);

void	sx(t_stack **x, int stack);
void	ss(t_stack **a, t_stack **b);
void	px(t_stack **x, t_stack **y, int stack);

void	rx(t_stack **x, int stack);
void	rr(t_stack **a, t_stack **b);
void	rrx(t_stack **x, int stack);
void	rrr(t_stack **a, t_stack **b);

#endif