/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:52:46 by mehkekli          #+#    #+#             */
/*   Updated: 2023/11/24 16:52:49 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr_hex_c(void *addr)
{
	char	*c;
	int		i;

	c = "0123456789abcdef";
	i = 0;
	if ((size_t)addr > 15)
		i += ft_putaddr_hex_c((void *)((size_t)addr / 16));
	i += ft_putchar_c(c[(size_t)addr % 16]);
	return (i);
}

int	ft_putaddr_c(void *addr)
{
	int	i;

	i = 0;
	i += ft_putstr_c("0x");
	i += ft_putaddr_hex_c(addr);
	return (i);
}
