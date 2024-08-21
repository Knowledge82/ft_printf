/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:22:34 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/08/21 14:25:57 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned(unsigned int nb, int *len)
{
	if (nb >= 10)
	{
		print_unsigned((nb / 10), len);
		print_unsigned((nb % 10), len);
	}
	else
		print_char(nb + '0', len);
}
