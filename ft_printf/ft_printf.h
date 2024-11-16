/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <sasano.stu>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:31:45 by sasano            #+#    #+#             */
/*   Updated: 2023/11/17 18:46:33 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(unsigned char c);
int	ft_putstr(char *str);
int	ft_putptr(uintptr_t ptr, const char format);
int	ft_putnbr(int nb);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_putnbr_hex(unsigned int nb, const char format);

#endif