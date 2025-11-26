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

static void	output_left_align(char *ptr_str, int width_padding, int *len)
{
	print_str(ptr_str, len);
	while (width_padding > 0)
	{
		print_char(' ', len);
		width_padding--;
	}
}

static void	output_right_align(char *ptr_str, int width_padding, int *len)
{
	while (width_padding > 0)
	{
		print_char(' ', len);
		width_padding--;
	}
	print_str(ptr_str, len);
}

static char	*make_ptr_str(unsigned long ptr)
{
	char	*total_str;
	char	*hex_str;
	int	hex_len;
	int	i;

	if (ptr == 0)
		return (ft_strdup("(nil)"));
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

void	print_pointer_with_flags(unsigned long ptr, t_flags *flags, int *len)
{
	char	*ptr_str;
	int	ptr_len;
	int	width_padding;

	if (flags->no_flags)
	{
		print_pointer(ptr, len);
		return ;
	}
	ptr_str = make_ptr_str(ptr);
	if (!ptr_str)
		return ;
	ptr_len = ft_strlen(ptr_str);
	width_padding = 0;
	if (flags->width > ptr_len)
		width_padding = flags->width - ptr_len;
	if (flags->minus)
		output_left_align(ptr_str, width_padding, len);
	else
		output_right_align(ptr_str, width_padding, len);
	free(ptr_str);
}
