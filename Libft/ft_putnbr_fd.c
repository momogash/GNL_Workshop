/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momogash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:57:54 by momogash          #+#    #+#             */
/*   Updated: 2019/06/20 15:50:23 by momogash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0 && fd <= 2)
	{
		if (n == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-n, fd);
		}
		else if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
}
