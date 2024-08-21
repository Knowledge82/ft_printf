/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:09:26 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/08/21 16:43:10 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(void *ptr, int *len)
{
	unsigned long long	address;

	address = (unsigned long long)ptr;
	if (address == 0)
	{
		print_str("(nil)", len);
		return ;
	}
	else
	{
		print_str("0x", len);
		print_hexa(address, 'x', len);
	}
}
