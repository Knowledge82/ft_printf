/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:24:26 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/22 13:15:37 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	minus;     // '-' выравнивание влево
	int	zero;      // '0' заполнение нулями
	int	width;     // минимальная ширина поля
	int	precision; // точность (.число)
	int	hash;      // '#' альтернативная форма
	int	plus;      // '+' знак всегда
	int	space;     // ' ' пробел для положительных
	int	has_prec;  // была ли указана точность
}	t_flags;

//prototypes
int		ft_printf(const char *str, ...);
void	print_char(char c, int *len);
void	print_str(char *str, int *len);
void	print_int(int nb, int *len);
void	print_unsigned(unsigned int nb, int *len);
void	print_hexa(unsigned int nb, const char c, int *len);
void	print_pointer(unsigned long ptr, int *len);

// %[flags][width][.precision]conversion

#ifdef BONUS
// bonus funcs

#endif

#endif
