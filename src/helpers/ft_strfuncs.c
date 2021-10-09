#include "push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_put_error(void)
{
	ft_putstr("Error\n");
	exit(-1);
}

int	ft_isdigit(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '-')
		str++;
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str && !(*str >= '0' && *str <= '9'))
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	long	i;
	int		minus;

	i = 0;
	minus = 1;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
		i = i * 10 + (*str++ - '0');
	if (!(i * minus >= INT_MIN && i * minus <= INT_MAX))
		ft_put_error();
	return (i * minus);
}
