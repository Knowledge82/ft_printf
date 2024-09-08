/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:52:16 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/09/08 15:15:54 by vdarsuye         ###   ########.fr       */
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
		print_pointer(va_arg(params, unsigned long), len);
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
	int		len;
	int		i;
	va_list	params;

	va_start(params, str);
	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
				ft_check(params, str[++i], &len);
		}
		else
			print_char(str[i], &len);
		i++;
	}
	va_end(params);
	return (len);
}
