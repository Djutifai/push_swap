#include "push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_atoi(char *str)
{
	long i;

	i = 0;
	while (*str && *str >= '0' && *str <= '9')
		i = i * 10 + (*str++ - '0');
	if (*str)
		if (!(*str >= '0' && *str <= '9'))

}
