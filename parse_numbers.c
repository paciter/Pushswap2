#include "push_swap.h"
 /*ce que je t ai deja expliquer sur l autre git les fonctions disent ce qu elles font et print_stack_a c est pour voir si tout se trie bien */
t_stack	*parse_numbers(int argc, char **argv, int start_index)
{
	t_stack	*stack_a;
	t_stack	*new;
	int		i;
	int		num;

	stack_a = NULL;
	i = start_index;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			free_stack(&stack_a);
			error_exit();
		}
		num = ft_atoi(argv[i]);
		new = stack_new(num);
		if (!new)
		{
			free_stack(&stack_a);
			error_exit();
		}
		stack_add_back(&stack_a, new);
		i++;
	}
	return (stack_a);
}
void    print_stack_a(t_stack *a)
{
    t_stack *current;

    current = a;
    printf("Stack A:\n");

    if (!a)
    {
        printf("  (vide)\n");
        return;
    }

    while (current)
    {
        printf("  value: %d", current->value, current->index);
        current = current->next;
    }
    printf("\n");
}
