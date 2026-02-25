#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>


typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
void	free_stack(t_stack **stack);
t_stack	*get_last(t_stack *stack);
int		ft_atoi(const char *str);
int		is_number(char *str);
int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
int		check_args(int argc, char **argv);
t_stack	*parse_numbers(int argc, char **argv, int start_index);
void    print_stack_a(t_stack *a);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	simple_sort(t_stack **a, t_stack **b);
int		find_min_pos(t_stack *stack);
void	error_exit(void);

#endif