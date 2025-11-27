#include "ft_printf.h"

static void	output_left_align(t_num_str str, t_padding pad, int *len)
{
	if (str.prefix)
		print_str(str.prefix, len);
	else if (str.sign != '\0')
		print_char(str.sign, len);
	while (pad.precision > 0)
	{
		print_char('0', len);
		pad.precision--;
	}
	print_str(str.num, len);
	while (pad.width > 0)
	{
		print_char(' ', len);
		pad.width--;
	}
}

static void	output_zero_padding(t_num_str str, t_padding pad, int *len)
{
	if (str.prefix)
		print_str(str.prefix, len);
	else if (str.sign != '\0')
		print_char(str.sign, len);
	while (pad.width > 0)
	{
		print_char('0', len);
		pad.width--;
	}
	print_str(str.num, len);
}

static void	output_right_align(t_num_str str, t_padding pad, int *len)
{
	while (pad.width > 0)
	{
		print_char(' ', len);
		pad.width--;
	}
	if (str.prefix)
		print_str(str.prefix, len);
	else if (str.sign != '\0')
		print_char(str.sign, len);
	while (pad.precision > 0)
	{
		print_char('0', len);
		pad.precision--;
	}
	print_str(str.num, len);
}

void	output_formatted(t_num_str str, t_padding pad,
			t_flags *flags, int *len)
{
	if (flags->minus)
		output_left_align(str, pad, len);
	else if (flags->zero && flags->has_prec == -1)
		output_zero_padding(str, pad, len);
	else
		output_right_align(str, pad, len);
}
