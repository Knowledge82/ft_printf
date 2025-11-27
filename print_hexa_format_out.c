/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_format_out.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:33:15 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/24 19:37:06 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	output_left_align(t_hex_str str, t_padding pad, int *len)
{
	print_str(prefix, len);
	while (pad.precision > 0)
	{
		print_char('0', len);
		pad.precision--;
	}
	print_str(num_str, len);
	while (pad.width > 0)
	{
		print_char(' ', len);
		pad.width--;
	}
}

static void	output_zero_padding(t_hex_str str, t_padding pad, int *len)
{
	print_str(prefix, len);
	while (pad.width > 0)
	{
		print_char('0', len);
		pad.width--;
	}
	print_str(num_str, len);
}

static void	output_right_align(t_hex_str str, t_padding pad, int *len)
{
	while (pad.width > 0)
	{
		print_char(' ', len);
		pad.width--;
	}
	print_str(prefix, len);
	while (pad.precision > 0)
	{
		print_char('0', len);
		pad.precision--;
	}
	print_str(num_str, len);
}

void	output_formatted_hex(t_hex_str str, t_padding pad,
			t_flags *flags, int *len)
{
	if (flags->minus)
		output_left_align(str, pad, len);
	else if (flags->zero && flags->has_prec == -1)
		output_zero_padding(str, pad, len);
	else
		output_right_align(str, pad, len);
}
