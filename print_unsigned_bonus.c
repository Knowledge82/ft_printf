/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:43:26 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/24 17:43:30 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	output_formatted_unsigned(char *num_str, int precision_padding,
			int width_padding, t_flags *flags, int *len)
{
	if (flags->minus)
	{
		while(precision_padding > 0)
		{
			print_char('0', len);
			precision_padding--;
		}
		print_str(num_str, len);
		while(width_padding > 0)
		{
			print_char(' ', len);
			width_padding--;
		}
	}
	else if (flags->zero && !flags->has_prec)
	{
		while (width_padding > 0)
		{
			print_char('0', len);
			width_padding--;
		}
			print_str(num_str, len);
	}
	else
	{
		while (width_padding > 0)
		{
			print_char(' ', len);
			width_padding--;
		}
		while (precision_padding > 0)
		{
			print_char('0', len);
			precision_padding--;
		}
		print_str(num_str, len);
	}
}

void	print_unsigned_with_flags(unsigned int n, t_flags *flags, int *len)
{
	char	*num_str;
	char	*original_str;
	int	num_len;
	int	precision_padding;
	int	width_padding;
	int	content_len;

	if (n == 0 && flags->has_prec && flags->precision == 0)
		num_str = ft_strdup("");
	else
		num _str = ft_uitoa(n);
	original_str = num_str;
	num_len = ft_strlen(num_str);
	precision_padding = 0;
	if (flags->has_prec && flags->precision > num_len)
		precision_padding = flags->precision - num_len;
	content_len = precision_padding + num_len;
	width_padding = 0;
	if (flags->width > content_len)
		width_padding = flags->width - content_len;
	output_formatted_unsigned(num_str, precision_padding,
			width_padding, flags, len);
	free(original_str);
}
