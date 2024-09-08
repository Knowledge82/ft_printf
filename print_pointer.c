/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:09:26 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/09/08 15:28:54 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexa_pointer(unsigned long ptr, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr >= 16)
		print_hexa_pointer(ptr / 16, len);
	print_char(base[ptr % 16], len);
}

void	print_pointer(unsigned long ptr, int *len)
{
	if (ptr == '\0')
	{
		print_str("(nil)", len);
		return ;
	}
	else
	{
		print_str("0x", len);
		print_hexa_pointer(ptr, len);
	}
}
