#include "push_swap.h"

int		*ft_create_stack(int amount)
{
	int	*stack;

	stack = malloc(sizeof(*stack) * amount);
	if (stack == NULL)
		return (NULL);
	return (stack);
}

void	ft_free_all(int **stacka, int **stackb)
{
	if (*stacka)
		free(*stacka);
	if (*stackb)
		free(*stackb);
	exit(-1);
}

void	ft_init_stacks(int	**stacka, int **stackb, char **argv, int argc)
{
	int argi;
	int stacki;

	argi = 1;
	stacki = 0;
	*stacka = ft_create_stack(argc - 1);
	if (!*stacka)
		ft_free_all(stacka, stackb);
	*stackb = ft_create_stack(argc - 1);
	if (!*stackb)
		ft_free_all(stacka, stackb);
	while (argi != argc)
		stacka[stacki++] = ft_atoi(argv[argi++]);
}
