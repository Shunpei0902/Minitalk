/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <sasano.stu>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:12:07 by sasano            #+#    #+#             */
/*   Updated: 2023/11/17 18:44:39 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}

int	ft_putptr(uintptr_t ptr, const char format)
{
	int	count;

	count = 0;
	if (ptr >= 16)
	{
		count += ft_putptr(ptr / 16, format);
		count += ft_putptr(ptr % 16, format);
	}
	else if (ptr < 10)
		count += ft_putchar(ptr + '0');
	else
		count += ft_putchar(ptr + 'a' - 10);
	return (count);
}
