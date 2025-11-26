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

static void	output_left_align(char *num_str, char *prefix,
		int prec_pad, int width_pad, int *len)
{
	print_str(prefix, len);
	while (prec_pad > 0)
	{
		print_char('0', len);
		prec_pad--;
	}
	print_str(num_str, len);
	while (width_pad > 0)
	{
		print_char(' ', len);
		width_pad--;
	}
}

static void	output_zero_padding(char *num_str, char *prefix,
		int width_pad, int *len)
{
	print_str(prefix, len);
	while (width_pad > 0)
	{
		print_char('0', len);
		width_pad--;
	}
	print_str(num_str, len);
}

static void	output_right_align(char *num_str, char *prefix,
		int prec_pad, int width_pad, int *len)
{
	while (width_pad > 0)
	{
		print_char(' ', len);
		width_pad--;
	}
	print_str(prefix, len);
	while (prec_pad > 0)
	{
		print_char('0', len);
		prec_pad--;
	}
	print_str(num_str, len);
}

void	output_formatted_hex(char *num_str, char *prefix, int prec_pad,
		int width_pad, t_flags *flags, int *len)
{
	if (flags->minus)
		output_left_align(num_str, prefix, prec_pad, width_pad, len);
	else if (flags->zero && flags->has_prec == -1)
		output_zero_padding(num_str, prefix, width_pad, len);
	else
		output_right_align(num_str, prefix, prec_pad, width_pad, len);
}
