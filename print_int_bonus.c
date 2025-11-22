/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:52:37 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/22 19:07:45 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*convert_number_to_string(int n, t_flags *flags)
{
	if (n == 0 && flags->has_prec && flags->precision == 0)
		return (ft_strdup(""));//edge case: %.0d with 0 = "". printf("%.0d", 0);
	else
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
	else
		return ('\0');
}
//Точность для чисел означает минимальное количество цифр. Если цифр меньше, дополняем нулями слева.
static int	calculate_precision_padding(t_flags *flags, int num_len)
{
	if (flags->has_prec && flags->precision > num_len)
		return (flags->precision - num_len);
	else
		return (0);
}
//Ширина — это минимальная ширина всего поля вывода. Если контент меньше, добавляем пробелы (или нули, если флаг 0)
static int	calculate_width_padding(t_flags *flags, int content_len)
{
	if (flags->width > content_len)
		return (flags->width - content_len);
	else
		return (0);
}

// for %d and %i works all flags: width, prec, -, 0, +, ' '
void	print_int_with_flags(int n, t_flags *flags, int *len)
{
	char	*num_str;
	char	*original_str;
	int	num_len;
	char	sign;
	int	sign_len;
	int	precision_padding;
	int	width_padding;
	int	content_len;

}
