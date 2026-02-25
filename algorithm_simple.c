#include "push_swap.h"

int	find_min_pos(t_stack *stack)
{
	int		min;
	int		pos;
	int		min_pos;

	if (!stack)
		return (-1);
	min = stack->value;
	pos = 0;
	min_pos = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void	rotate_min_to_top(t_stack **a, int min_pos, int size)
{
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a);
			min_pos++;
		}
	}
}

void	simple_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	min_pos;

	size = stack_size(*a);
	if (size == 2)
	{
		sort_two(a);
		return ;
	}
	if (size == 3)
	{
		sort_three(a);
		return ;
	}
	while (stack_size(*a) > 3)
	{
		min_pos = find_min_pos(*a);
		rotate_min_to_top(a, min_pos, stack_size(*a));
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}