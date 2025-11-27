/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:24:26 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/24 21:05:12 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

// %[flags][width][.precision]conversion
typedef struct s_flags
{
	int	minus;// '-' выравнивание влево
	int	zero;// '0' заполнение нулями
	int	width;// минимальная ширина поля
	int	precision;// точность (.число)
	int	hash;// '#' альтернативная форма
	int	plus;// '+' знак всегда
	int	space;// ' ' пробел для положительных
	int	has_prec;// была ли указана точность
	int	no_flags;
}	t_flags;

typedef struct s_padding
{
	int	precision;
	int	width;
}	t_padding;

typedef struct s_num_str
{
	char	*original_str;
	char	*num;
	char	*prefix;
	char	sign;
}	t_num_str;

//prototypes
int		ft_printf(const char *str, ...);
void	print_char(char c, int *len);
void	print_str(char *str, int *len);
void	print_int(int nb, int *len);
void	print_unsigned(unsigned int nb, int *len);
void	print_hexa(unsigned int nb, const char c, int *len);
void	print_pointer(unsigned long ptr, int *len);

//bonus
void	init_flags(t_flags *flags);
int		is_flag(char c);
int		handle_flags(const char *str, int *i, t_flags *flags);
void	ft_check_with_flags(va_list params, char c, t_flags *flags, int *len);
void	print_char_with_flags(char c, t_flags *flags, int *len);
void	print_hexa_with_flags(unsigned int n, char format,
			t_flags *flags, int *len);
void	print_int_with_flags(int n, t_flags *flags, int *len);
void	print_str_with_flags(char *str, t_flags *flags, int *len);
void	print_unsigned_with_flags(unsigned int n, t_flags *flags, int *len);
void	print_pointer_with_flags(unsigned long ptr, t_flags *flags, int *len);
void	output_formatted(t_num_str str, t_padding pad,
			t_flags *flags, int *len);

#endif
