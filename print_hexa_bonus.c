/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:42:36 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/24 18:42:18 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_prefix(unsigned int n, char format, t_flags *flags)
{
	if (flags->hash && n != 0)
	{
		if (format == 'x')
			return ("0x");
		else
			return ("0X");
	}
	return ("");
}

static char	*make_hex_string(unsigned int n, char format, t_flags *flags)
{
	if (n == 0 && flags->has_prec == 1 && flags->precision == 0)
		return (ft_strdup(""));
	else
		return (ft_uitoa_hex(n, format));
}

static t_padding	calculate_hex_padding(t_flags *flags, int num_len,
		int prefix_len)
{
	t_padding	pad;
	int			content_len;

	pad.precision = 0;
	if (flags->has_prec == 1 && flags->precision > num_len)
		pad.precision = flags->precision - num_len;
	content_len = prefix_len + pad.precision + num_len;
	pad.width = 0;
	if (flags->width > content_len)
		pad.width = flags->width - content_len;
	return (pad);
}

void	print_hexa_with_flags(unsigned int n, char format,
		t_flags *flags, int *len)
{
	t_padding	pad;
	t_hex_str	str;
	char		*original_str;

	if (flags->no_flags)
		return (print_hexa(n, format, len));
	str.num_str = make_hex_string(n, format, len);
	original_str = str.num_str;
	str.prefix = get_prefix(n, format, flags);
	pad = calculate_hex_padding(flags, ft_strlen(str.num_str),
			ft_strlen(str.prefix));
	output_formatted_hex(str, pad, flags, len);
	free(original_str);
}
