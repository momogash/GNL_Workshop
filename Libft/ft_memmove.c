/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momogash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:13:25 by momogash          #+#    #+#             */
/*   Updated: 2019/06/21 15:05:02 by momogash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;

	dst1 = (char *)dst;
	src1 = (char *)src;
	if (dst1 > src1)
	{
		while (len--)
		{
			dst1[len] = src1[len];
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst1);
}
