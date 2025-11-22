/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:16:44 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/22 17:27:26 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// for %c works flag '-' and width
void	printf_char_with_flags(char c, t_flags *flags, int *len)
{
	int	padding;

	padding = 0;//num of spaces for padding
	if (flags->width > 1)
		padding = flags->width - 1;
	if (flags->minus)//align left
	{
		print_char(c, len);
		while (padding-- > 0)
			print_char(' ', len);
	}
	else//align right
	{
		while (padding-- > 0)
			print_char(' ', len);
		print_char(c, len);
	}
}
