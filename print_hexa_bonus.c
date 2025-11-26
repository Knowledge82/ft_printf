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

void	print_hexa_with_flags(unsigned int n, char format, t_flags *flags, int *len)
{
	char	*num_str;
	char	*original_str;
	char	*prefix;
	int	num_len;
	int	prefix_len;
	int	precision_padding;
	int	width_padding;
	int	content_len;

	if (flags->no_flags)
	{
		print_hexa(n, format, len);
		return ;
	}
	if (n == 0 && flags->has_prec == 1 && flags->precision == 0)
		num_str = ft_strdup("");
	else
		num_str = ft_uitoa_hex(n, format);
	original_str = num_str;
	prefix = get_prefix(n, format, flags);
	prefix_len = ft_strlen(prefix);
	num_len = ft_strlen(num_str);
	precision_padding = 0;
	if (flags->has_prec && flags->precision > num_len)
		precision_padding = flags->precision - num_len;
	content_len = prefix_len + precision_padding + num_len;
	width_padding = 0;
	if (flags->width > content_len)
		width_padding = flags->width - content_len;
	output_formatted_hex(num_str, prefix, precision_padding, width_padding, flags, len);
	free(original_str);
}
