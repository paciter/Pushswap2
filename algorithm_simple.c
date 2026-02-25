#include "push_swap.h"
/*dcp ici viiens le plus "complique" donc pour l algo on cherrche le pluss petit de la stack a qu om va push dans b  donc on creer la fonction find_min_pos pour savoir ou il se trouve*/

/* la premierre fonction se deroule de maniere qu on deroule la stack tant que toute la liste a pas etait faites , on ert la pour trouveer le plus petit caracteres,
 on initialise le min avec la valeur du  premier noeud et la position a 0 ensuiite on parcours la pile  si on croise une valeur 
  un noeud plus petite que celle de base alors on la change par la plus petite et par sa position, on defile toute la liste avec ceette logique */

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
/*car il y a aussi une seul maniere de trier pour 2 jsp si tu me comprends tu me dis en dm */
void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
/* on utilise sort_three carr il ya qu  une seule maniere de trierr quand il en reste 3 je sais pas i tu m;as compris 
((*a) sommet de la pile) dcp (*a)next -> value = deuxieme pos et apres 3ieme pos (*a)next ->next ->value  */
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
/* pour push dans la stack b on doit dabord push le min en haut de a donc on fait une fonction pour laa remonter au dedbut de la liste */
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
/*la fonction qu on va appeler dans le main pour execeuter l algo */
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