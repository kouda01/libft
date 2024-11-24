/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:26:34 by yel-mako          #+#    #+#             */
/*   Updated: 2024/10/27 02:13:20 by yel-mako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (src_len < size - 1)
		ft_memcpy(dest, src, src_len + 1);
	else
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (src_len);
}
