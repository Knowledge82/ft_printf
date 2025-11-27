/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:38:47 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/24 19:50:54 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_hex_digits(unsigned int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

char	*ft_uitoa_hex(unsigned int n, char format)
{
	size_t	len;
	char	*base;
	char	*str;

	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	else
		write(STDERR_FILENO, "Wrong format. Use x or X\n", 24);
	len = count_hex_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		len--;
		str[len] = base[n % 16];
		n = n / 16;
	}
	return (str);
}
