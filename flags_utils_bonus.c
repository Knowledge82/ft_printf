#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	ft_memset(flags, 0, sizeof(t_flags));
	flags->has_prec = -1;
	flags->no_flags = 1;
}

int	is_flag(char c)
{
	return (c == '-' || c == '0' || c == '#'
		|| c == '+' || c == ' ');
}
