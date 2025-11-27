/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:10:09 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/24 20:54:29 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*convert_ptr_to_hex(unsigned long ptr)
{
	char	*total_str;
	char	*hex_str;
	int		hex_len;
	int		i;

	hex_str = ft_ultoa_hex(ptr);
	if (!hex_str)
		return (NULL);
	hex_len = ft_strlen(hex_str);
	total_str = (char *)malloc(sizeof(char) * (hex_len + 3));
	if (!total_str)
		return (free(hex_str), NULL);
	total_str[0] = '0';
	total_str[1] = 'x';
	i = 0;
	while (hex_str[i])
	{
		total_str[i + 2] = hex_str[i];
		i++;
	}
	total_str[i + 2] = '\0';
	free(hex_str);
	return (total_str);
}

static t_num_str	make_ptr_string(unsigned long ptr)
{
	t_num_str	str;

	if (ptr == 0)
		str.original_str = ft_strdup("(nil)");
	else
		str.original_str = convert_ptr_to_hex(ptr);
	str.num = str.original_str;
	str.sign = '\0';
	str.prefix = NULL;
	return (str);
}

static t_padding	calculate_ptr_padding(t_flags *flags, int ptr_len)
{
	t_padding	pad;

	pad.precision = 0;
	pad.width = 0;
	if (flags->width > ptr_len)
		pad.width = flags->width - ptr_len;
	return (pad);
}

void	print_pointer_with_flags(unsigned long ptr, t_flags *flags, int *len)
{
	t_num_str	str;
	t_padding	pad;

	if (flags->no_flags)
		return (print_pointer(ptr, len));
	str = make_ptr_string(ptr);
	if (!str.original_str)
		return ;
	pad = calculate_ptr_padding(flags, ft_strlen(str.num));
	output_formatted(str, pad, flags, len);
	free(str.original_str);
}
