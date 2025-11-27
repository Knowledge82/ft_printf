/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:52:37 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/23 12:36:05 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*convert_int_to_string(int n, t_flags *flags)
{
	if (n == 0 && flags->has_prec == 1 && flags->precision == 0)
		return (ft_strdup(""));
	return (ft_itoa(n));
}

static char	get_sign(int n, t_flags *flags)
{
	if (n < 0)
		return ('-');
	else if (flags->plus)
		return ('+');
	else if (flags->space)
		return (' ');
	return ('\0');
}

static t_padding	calculate_int_padding(t_flags *flags, int num_len,
		int sign_len)
{
	t_padding	pad;
	int			content_len;

	pad.precision = 0;
	if (flags->has_prec == 1 && flags->precision > num_len)
		pad.precision = flags->precision - num_len;
	content_len = sign_len + pad.precision + num_len;
	pad.width = 0;
	if (flags->width > content_len)
		pad.width = flags->width - content_len;
	return (pad);
}

static t_num_str	make_int_string(int n, t_flags *flags)
{
	t_num_str	str;

	str.original_str = convert_int_to_string(n, flags);
	str.num = str.original_str;
	str.sign = get_sign(n, flags);
	str.prefix = NULL;
	if (n < 0 && str.num[0] == '-')
		str.num++;
	return (str);
}

void	print_int_with_flags(int n, t_flags *flags, int *len)
{
	t_num_str	str;
	t_padding	pad;
	int			sign_len;

	if (flags->no_flags)
		return (print_int(n, len));
	str = make_int_string(n, flags);
	sign_len = 0;
	if (str.sign != '\0')
		sign_len = 1;
	pad = calculate_int_padding(flags, ft_strlen(str.num), sign_len);
	output_formatted(str, pad, flags, len);
	free(str.original_str);
}
