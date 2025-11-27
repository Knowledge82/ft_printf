/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:27:38 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/22 17:54:34 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str_with_flags(char *str, t_flags *flags, int *len)
{
	int	str_len;
	int	padding;
	int	i;

	if (flags->no_flags)
		return (print_str(str, len));
	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (flags->has_prec == 1 && flags->precision < str_len)
		str_len = flags->precision;
	padding = 0;
	if (flags->width > str_len)
		padding = flags->width - str_len;
	if (!flags->minus)
		while (padding-- > 0)
			print_char(' ', len);
	i = 0;
	while (i < str_len)
		print_char(str[i++], len);
	if (flags->minus)
		while (padding-- > 0)
			print_char(' ', len);
}
