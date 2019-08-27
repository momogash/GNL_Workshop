/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momogash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:41:16 by momogash          #+#    #+#             */
/*   Updated: 2019/06/18 16:36:45 by momogash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	while (dst[j] && j < size)
		j++;
	while ((src[k]) && ((j + k + 1) < size))
	{
		dst[j + k] = src[k];
		k++;
	}
	if (j != size)
		dst[j + k] = '\0';
	return (j + ft_strlen(src));
}
