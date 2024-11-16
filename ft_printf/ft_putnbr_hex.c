/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <sasano.stu>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:31:24 by sasano            #+#    #+#             */
/*   Updated: 2023/10/19 23:28:44 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nb, const char format)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_putnbr_hex(nb / 16, format);
		count += ft_putnbr_hex(nb % 16, format);
	}
	else if (nb < 10)
		count += ft_putchar(nb + '0');
	else
	{
		if (format == 'X')
			count += ft_putchar(nb + 'A' - 10);
		else
			count += ft_putchar(nb + 'a' - 10);
	}
	return (count);
}
