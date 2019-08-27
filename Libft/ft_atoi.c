/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momogash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:14:36 by momogash          #+#    #+#             */
/*   Updated: 2019/06/20 12:09:58 by momogash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	i;
	int		num;

	i = 0;
	while ((*str >= '\t' && *str <= '\r') || (*str == 32))
		str++;
	if (*str == '-')
		num = -1;
	else
		num = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
		i = (i * 10) + (*str++ - '0');
	if (i < 0 && num == 1)
		return (-1);
	if (i < 0)
		return (0);
	return (i * num);
}
