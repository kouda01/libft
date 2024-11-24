/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 02:20:52 by yel-mako          #+#    #+#             */
/*   Updated: 2024/11/16 23:13:03 by yel-mako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dlen >= size)
		dlen = size;
	if (dlen == size)
		return (size + slen);
	if (slen < size - dlen)
		ft_memcpy(dst + dlen, src, slen + 1);
	else
	{
		ft_memcpy(dst + dlen, src, size - dlen - 1);
		dst[size - 1] = '\0';
	}
	return (dlen + slen);
}
