/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:52:16 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/08/21 14:46:15 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(va_list params, char c, int *len)
{
	if (c == 'c')
		print_char(va_arg(params, int), len);
	else if (c == 's')
		print_str(va_arg(params, char *), len);
	else if (c == 'p')
		print_pointer(va_arg(params, void *), len);
	else if (c == 'd' || c == 'i')
		print_int(va_arg(params, int), len);
	else if (c == 'u')
		print_unsigned(va_arg(params, unsigned int), len);
	else if (c == 'x' || c == 'X')
		print_hexa(va_arg(params, unsigned int), c, len);
	else if (c == '%')
		print_char('%', len);
}

int	ft_printf(const char *str, ...)
{
	int	len;
	va_list	params;

	va_start(params, str);
	len = 0;

	while(*str)
	{
		if(*str == '%')
		{
			str++;
			if(*str)
			{
				ft_check(params, *str, &len);
				str++;
			}
		}
		else
		{
			print_char(*str, &len);
			str++;
		}
	}
	va_end(params);
	return (len);
}
