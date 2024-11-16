/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <sasano.stu>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:31:23 by sasano            #+#    #+#             */
/*   Updated: 2023/11/17 18:44:22 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putptr(va_arg(args, uintptr_t), 'x');
	}
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += check_format(args, *format);
		}
		else
		{
			ft_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

/* # define NUM INT32_MIN - 1

int	main(void) {
	printf("%d\n", ft_printf("Hello, %c\n", 'c'));
	printf("%d\n", printf("Hello, %c\n", 'c'));
	printf("%d\n", ft_printf("Hello, %s\n", "world!"));
	printf("%d\n", printf("Hello, %s\n", "world!"));

	printf("%d\n", ft_printf("Hello, %s\n", "world!"));
	printf("%d\n", printf("Hello, %s\n", "world!"));
	void *null = NULL;
	printf("%d\n", ft_printf("Hello, %p\n", null));
	printf("%d\n", printf("Hello, %p\n", null));
	printf("%d\n", ft_printf("Hello, %d\n", NUM));
	printf("%d\n", printf("Hello, %d\n", NUM));
	printf("%d\n", ft_printf("Hello, %i\n", NUM));
	printf("%d\n", printf("Hello, %i\n", NUM));
	printf("%d\n", ft_printf("Hello, %u\n", NUM));
	printf("%d\n", printf("Hello, %u\n", NUM));
	printf("%d\n", ft_printf("Hello, %x\n", NUM));
	printf("%d\n", printf("Hello, %x\n", NUM));
	printf("%d\n", ft_printf("Hello, %X\n", NUM));
	printf("%d\n", printf("Hello, %X\n", NUM));
	printf("%d\n", ft_printf("Hello, %%\n"));
	printf("%d\n", printf("Hello, %%\n"));
	printf("%d\n", ft_printf("%c!%c!%c\n", '0', 0, '1'));
	printf("%d\n", printf("%c!%c!%c\n", '0', 0, '1'));
	printf("%d\n", ft_printf("%c!%c!%c\n", ' ', ' ', ' '));
	printf("%d\n", printf("%c!%c!%c\n", ' ', ' ', ' '));
	printf("%d\n", ft_printf(" NULL %s NULL ", NULL));
	printf("%d\n", printf(" NULL %s NULL ", NULL));
	char str[2] = "a\0";
	printf("%d\n", ft_printf("%cadf%sadf%p%d%i%u%x%X%%asdf\n", 'a', "get wild",
			str, -1, -1, -1, -1, -1));
	printf("%d\n", printf("%cadf%sadf%p%d%i%u%x%X%%asdf\n", 'a', "get wild",
			str, -1, -1, -1, -1, -1));

	char *str = malloc(INT32_MAX);
	size_t i;
	for (i = 0; i < INT32_MAX - 1; ++i)
	{
		str[i] = 'a';
	}
	str[INT32_MAX] = '\0';

	printf("%d\n", ft_printf("%s\n", str));
	printf("%d\n", printf("%s\n", str));

	ft_printf("%c!%c!%c\n", '1', '2', '3')
	printf("%c!%c!%c\n", '1', '2', '3')
	ft_printf("%c!%c!%c\n", '2', '1', 0)
	printf("%c!%c!%c\n", '2', '1', 0)
	ft_printf("%c!%c!%c\n", 0, '1', '2')
	printf("%c!%c!%c\n", 0, '1', '2')


	ft_printf(" NULL %s NULL ", "")
	printf(" NULL %s NULL ", "")
	ft_printf("%%\n")
	printf("%%\n")
	ft_printf("%%%c\n", 'A')
	printf("%%%c\n", 'A')



	printf("%5%\n");
	printf("taaa %5s\n", "hello");
	printf("taaa %as\n", "hello");
	printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	ft_printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	ft_printf("%5%\n");
	return (0);

} */
