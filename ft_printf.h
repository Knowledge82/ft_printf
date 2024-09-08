/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:24:26 by vdarsuye          #+#    #+#             */
/*   Updated: 2024/09/08 14:56:15 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

//prototypes
int		ft_printf(const char *str, ...);
void	print_char(char c, int *len);
void	print_str(char *str, int *len);
void	print_int(int nb, int *len);
void	print_unsigned(unsigned int nb, int *len);
void	print_hexa(unsigned int nb, const char c, int *len);
void	print_pointer(unsigned long ptr, int *len);

#endif
