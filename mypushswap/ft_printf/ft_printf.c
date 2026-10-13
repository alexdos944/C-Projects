/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:30:51 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/13 18:29:26 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_resform(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		ft_putchar(va_arg(ap, int), &count);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), &count);
	else if (c == 'd')
		ft_putnbr(va_arg(ap, int), &count);
	else if (c == 'i')
		ft_putnbr(va_arg(ap, int), &count);
	else if (c == 'u')
		ft_putunsigned(va_arg(ap, unsigned int), &count);
	else if (c == 'x')
		ft_puthex(va_arg(ap, unsigned int), 0, &count);
	else if (c == 'X')
		ft_puthex(va_arg(ap, unsigned int), 1, &count);
	else if (c == '%')
		ft_putchar('%', &count);
	else if (c == 'p')
		ft_putptr(va_arg(ap, void *), &count);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count = count + ft_resform(*format, ap);
			format++;
		}
		else
		{
			write(1, format, 1);
			format++;
			count++;
		}
	}
	va_end(ap);
	return (count);
}
/*
int	main(void)
{
	int		n;
	int		ret1;
	int		ret2;
	char	*str;

	n = -42;
	str = "bonjour";
	printf("--- %%c ---\n");
	ret1 = ft_printf("ft:  %c\n", 'A');
	ret2 = printf("ref: %c\n", 'A');
	printf("ret ft:%d | ret ref:%d\n\n", ret1, ret2);

	printf("--- %%s ---\n");
	ret1 = ft_printf("ft:  %s\n", str);
	ret2 = printf("ref: %s\n", str);
	printf("ret ft:%d | ret ref:%d\n\n", ret1, ret2);

	printf("--- %%d ---\n");
	ret1 = ft_printf("ft:  %d\n", n);
	ret2 = printf("ref: %d\n", n);
	printf("ret ft:%d | ret ref:%d\n\n", ret1, ret2);

	printf("--- %%i ---\n");
	ret1 = ft_printf("ft:  %i\n", n);
	ret2 = printf("ref: %i\n", n);
	printf("ret ft:%d | ret ref:%d\n\n", ret1, ret2);

	printf("--- %%u ---\n");
	ret1 = ft_printf("ft:  %u\n", 4294967295u);
	ret2 = printf("ref: %u\n", 4294967295u);
	printf("ret ft:%d | ret ref:%d\n\n", ret1, ret2);

	printf("--- %%x ---\n");
	ret1 = ft_printf("ft:  %x\n", 255);
	ret2 = printf("ref: %x\n", 255);
	printf("ret ft:%d | ret ref:%d\n\n", ret1, ret2);

	printf("--- %%X ---\n");
	ret1 = ft_printf("ft:  %X\n", 255);
	ret2 = printf("ref: %X\n", 255);
	printf("ret ft:%d | ret ref:%d\n\n", ret1, ret2);

	printf("--- %%%% ---\n");
	ret1 = ft_printf("ft:  100%%\n");
	ret2 = printf("ref: 100%%\n");
	printf("ret ft:%d | ret ref:%d\n\n", ret1, ret2);

	printf("--- %%p ---\n");
	ret1 = ft_printf("ft:  %p\n", &n);
	ret2 = printf("ref: %p\n", &n);
	printf("ret ft:%d | ret ref:%d\n\n", ret1, ret2);
}*/