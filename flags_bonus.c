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

static void	parse_flags(const char *str, int *i, t_flags *flags)
{
	while (str[*i] && is_flag(str[*i]))
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
}

static void	parse_width(const char *str, int *i, t_flags *flags)
{
	if (ft_isdigit(str[*i]))
	{
		flags->width = ft_atoi(&str[*i]);
		while (ft_isdigit(str[*i]))
			(*i)++;
	}
}

static void	parse_precision(const char *str, int *i, t_flags *flags)
{
	if (str[*i] == '.')
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
}

static void	check_no_flags(t_flags *flags)
{
	if (!flags->minus && !flags->zero && !flags->plus
		&& !flags->space && !flags->hash
		&& flags->width == 0 && flags->has_prec == -1)
		flags->no_flags = 1;
	else
		flags->no_flags = 0;
}

int	handle_flags(const char *str, int *i, t_flags *flags)
{
	init_flags(flags);
	parse_flags(str, i, flags);
	parse_width(str, i, flags);
	parse_precision(str, i, flags);
	check_no_flags(flags);
	return (*i);
}
