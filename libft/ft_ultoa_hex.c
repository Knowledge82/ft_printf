/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:52:07 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/11/24 20:05:36 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_long_digits_hex(unsigned long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

char	*ft_ultoa_hex(unsigned long n)
{
	char	*str;
	char	*base;
	int		len;

	base = "0123456789abcdef";
	len = count_long_digits_hex(n);
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
