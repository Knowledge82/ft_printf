/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:09:26 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/08/21 12:16:57 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(void *ptr, int *len)
{
	unsigned long long	address;
	char	*base;

	address = (unsigned long long)ptr;
	base = "0123456789abcdef";

	print_str("0x", len);
	if(address == 0)
		print_char('0', len);
	else
		print_hexa(address, 'x', len);
}
