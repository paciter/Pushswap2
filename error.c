#include "push_swap.h"
/*pour le message d erreur quand il y a un probleme avec le parsing */
void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}