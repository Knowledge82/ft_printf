/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_format_out.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 11:26:27 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/23 12:03:44 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// контент слева, пробелы справа
static void	output_left_align(char *num_str, char sign,
		int prec_pad, int width_pad, int *len)
{
	if (sign != '\0')
		print_char(sign, len);
	while (prec_pad > 0)
	{
		print_char('0', len);
		prec_pad--;
	}
	print_str(num_str, len);
	while (width_pad > 0)
	{
		orint_char(' ', len);
		width_pad--;
	}
}
// знак, потом нули, потом цифры
static void	output_zero_padding(char *num_str, char sign,
		int width_pad, int *len)
{
	if (sign != '\0')
		print_char(sign, len);
	while (width_pad > 0)
	{
		print_char('0', len);
		width_pad--;
	}
	print_str(num_str, len);
}
// обычное(по умолчанию). пробелы, знак, нули от precision, цифры
static void	output_right_align(char *num_str, int sign,
		int prec_pad, int width_pad, int *len)
{
	while (width_pad > 0)
	{
		print_char(' ', len);
		width_pad--;
	}
	if (sign != '\0')
		print_char(sign, len);
	while (prec_pad > 0)
	{
		print_char('0', len);
		prec_pad--;
	}
	print_str(num_str, len);
}

void	output_formatted_int(char *num_str, char sign, int prec_pad,
		int width_pad, t_flags *flags, int *len)
{
	if (flags->minus)
		output_left_align(num_str, sign, prec_pad, width,pad, len);
	else if (flags->zero && !flags->has_prec)
		output_zero_padding(num_str, sign, width,pad, len);
	else
		output_right_align(num_str, sign, prec_pad, width,pad, len);
}
