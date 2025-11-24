/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:00:13 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/24 16:00:23 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_with_flags(va_list params, char c, t_flags *flags, int *len)
{
	if (c == 'c')
		print_char_with_flags(va_arg(params, int), flags, len);
	else if (c == 's')
		print_str_with_flags(va_arg(params, char *), flags, len);
	else if (c == 'p')
		print_pointer_with_flags(va_arg(params, unsigned long), flags, len);
	else if (c == 'd' || c == 'i')
		print_int_with_flags(va_arg(params, int), flags, len);
	else if (c == 'u')
		print_unsigned_with_flags(va_arg(params, unsigned int), flags, len);
	else if (c == 'x' || c == 'X')
		print_hexa_with_flags(va_arg(params, unsigned int), c, flags, len);
	else if (c == '%')
		print_char_with_flags('%', len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	params;
	t_flags	flags;

	va_start(params, str);
	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			parse_flags(str, &i, &flags);
			if (str[i] != '\0')
			{
				ft_check_with_flags(params, str[i], &flags, &len);
				i++;
			}
		}
		else
		{
			print_char(str[i], &len);
			i++;
		}
	}
	va_end(params);
	return (len);
}
