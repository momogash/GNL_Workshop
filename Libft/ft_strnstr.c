/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momogash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:27:29 by momogash          #+#    #+#             */
/*   Updated: 2019/06/24 10:23:31 by momogash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndle, size_t len)
{
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	if (ndle[0] == '\0')
		return ((char *)hay);
	while (hay[i] != '\0' && i < len)
	{
		k = 0;
		while (ndle[k] != '\0' && ndle[k] == hay[i + k] && i + k < len)
			k++;
		if (ndle[k] == '\0')
			return ((char *)hay + i);
		i++;
	}
	return (NULL);
}
