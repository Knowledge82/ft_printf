/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:39:03 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/08/15 15:43:14 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexa(unsigned int nb, const char c, int *len)
{
	char	*base;

	if (nb == 0)
		print_char('0', len);
	else
	{
		if (c == 'x')
			base = "0123456789abcdef";
		else
			base = "0123456789ABCDEF";
		if (nb >= 16)
		{
			print_hexa((nb / 16), c, len);
			print_hexa((nb % 16), c, len);
		}
		else
			print_char(base[nb], len);
	}
}
