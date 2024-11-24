/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:35:45 by yel-mako          #+#    #+#             */
/*   Updated: 2024/11/12 19:05:53 by yel-mako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int				len;
	unsigned int	num;

	len = 0;
	if (n < 0)
	{
		len++;
		num = -n;
	}
	else
		num = n;
	if (n == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	len = num_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}
