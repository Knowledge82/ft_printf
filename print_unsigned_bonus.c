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

static char	*convert_unsigned_to_str(unsigned int n, t_flags *flags)
{
	if (n == 0 && flags->has_prec && flags->precision == 0)
		return (ft_strdup(""));
	return (ft_uitoa(n));
}

static t_padding	calculate_unsigned_padding(t_flags *flags, int num_len)
{
	t_padding	pad;
	int			content_len;

	pad.precision = 0;
	if (flags->has_prec == 1 && flags->precision > num_len)
		pad.precision = flags->precision - num_len;
	content_len = pad.precision + num_len;
	pad.width = 0;
	if (flags->width > content_len)
		pad.width = flags->width - content_len;
	return (pad);
}

static t_num_str	make_unsigned_string(unsigned int n, t_flags *flags)
{
	t_num_str	str;

	str.original_str = convert_unsigned_to_str(n, flags);
	str.num = str.original_str;
	str.sign = '\0';
	str.prefix = NULL;
	return (str);
}

void	print_unsigned_with_flags(unsigned int n, t_flags *flags, int *len)
{
	t_num_str	str;
	t_padding	pad;

	if (flags->no_flags)
		return (print_unsigned(n, len));
	str = make_unsigned_string(n, flags);
	pad = calculate_unsigned_padding(flags, ft_strlen(str.num));
	output_formatted(str, pad, flags, len);
	free(str.original_str);
}
