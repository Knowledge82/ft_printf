/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:28:09 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/24 19:30:33 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_flags(t_flags *flags)
{
	ft_memset(flags, 0, sizeof(t_flags));
	flags->has_prec = -1;
	flags->no_flags = 1;
}

static int	is_flag(char c)
{
	return (c == '-' || c == '0' || c == '#'
		|| c == '+' || c == ' ');
}

// формат строки после %:    %[flags][width][.precision]conversion
int	parse_flags(const char *str, int *i, t_flags *flags)
{
	init_flags(flags);

	while (str[*i] && is_flag(str[*i]))//флаг
	{
		if (str[*i] == '-')
			flags->minus = 1;
		else if (str[*i] == '0')
			flags->zero = 1;
		else if (str[*i] == '#')
			flags->hash = 1;
		else if (str[*i] == '+')
			flags->plus = 1;
		else if (str[*i] == ' ')
			flags->space = 1;
		(*i)++;
	}
	if (ft_isdigit(str[*i]))//ширина
	{
		flags->width = ft_atoi(&str[*i]);// передаём строку от i и дальше
		while (ft_isdigit(str[*i]))//atoi парсит все цифры, поэтому вручную пропускаем
			(*i)++;
	}
	if (str[*i] == '.')//точность
	{
		flags->has_prec = 1;
		(*i)++;
		if (ft_isdigit(str[*i]))
		{
			flags->precision = ft_atoi(&str[*i]);
			while (ft_isdigit(str[*i]))
				(*i)++;
		}
	}
	else
		flags->precision = 0;
	if (!flags->minus && !flags->zero && !flags->plus
			&& !flags->space && !flags->hash
			&& flags->width == 0 && flags->has_prec == -1)
		flags->no_flags = 1;
	else
		flags->no_flags = 0;
	return (*i);
}
