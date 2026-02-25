#include "push_swap.h"
/**/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!check_args(argc, argv))
		error_exit();
	stack_a = parse_numbers(argc, argv, 1);
	if (!stack_a)
		error_exit();
	if (has_duplicates(stack_a))
	{
		free_stack(&stack_a);
		error_exit();
	}
	stack_b = NULL;
	if (!is_sorted(stack_a))
		simple_sort(&stack_a, &stack_b);
	if (is_sorted(stack_a))
		print_stack_a(stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}