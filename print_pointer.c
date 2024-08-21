/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:09:26 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/08/21 15:59:42 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(void *ptr, int *len)
{
	unsigned long long	address;

	address = (unsigned long long)ptr;
	print_str("0x", len);
	if (address == 0)
		print_char('0', len);
	else
		print_hexa(address, 'x', len);
}
