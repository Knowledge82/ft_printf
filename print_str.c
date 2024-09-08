/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:24:34 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/09/08 15:23:32 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(char *str, int *len)
{
	if (str == NULL)
		return (print_str("(null)", len));
	while (*str)
	{
		print_char(*str, len);
		str++;
	}
}
