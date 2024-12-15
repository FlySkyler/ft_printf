/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:44:21 by antbonin          #+#    #+#             */
/*   Updated: 2024/12/12 20:35:06 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && (*(format + 1) == ' ' || !*(format + 1)))
			return (-1);
		if (*format == '%' && *(format + 1))
		{
			count += ft_specifier(*(++format), ap);
		}
		else
			count += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	printf(" | ft_pri : %d\n", ft_printf("s : Hello %", "World"));
	printf(" | printf : %d\n", printf("s : Hello %", "World"));
	printf(" | ft_pri : %d\n", ft_printf("d : Hello %d", INT_MAX));
	printf(" | printf : %d\n", printf("d : Hello %d", INT_MAX));
	printf(" | ft_pri : %d\n", ft_printf("i : Hello %i", INT_MAX));
	printf(" | printf : %d\n", printf("i : Hello %i", INT_MAX));
	printf(" | ft_pri : %d\n", ft_printf("u : Hello %u", INT_MAX));
	printf(" | printf : %d\n", printf("u : Hello %u", INT_MAX));
	printf(" | ft_pri : %d\n", ft_printf("x : Hello %x", INT_MAX));
	printf(" | printf : %d\n", printf("x : Hello %x", INT_MAX));
	printf(" | ft_pri : %d\n", ft_printf("X : Hello %X", INT_MAX));
	printf(" | printf : %d\n", printf("X : Hello %X", INT_MAX));
	printf(" | ft_pri : %d\n", ft_printf("p : Hello %p", &ft_printf));
	printf(" | printf : %d\n", printf("p : Hello %p", &ft_printf));
	printf(" ft_printf : %d\n", ft_printf(NULL));
	printf(" printf : %d\n", printf(NULL));
	printf(" | ft_pri : %d\n", ft_printf("d : Hello %d", INT_MIN));
	printf(" | printf : %d\n", printf("d : Hello %d", INT_MIN));
	printf(" | ft_pri : %d\n", ft_printf("i : Hello %i", INT_MIN));
	printf(" | printf : %d\n", printf("i : Hello %i", INT_MIN));
	printf(" | ft_pri : %d\n", ft_printf("u : Hello %u", INT_MIN));
	printf(" | printf : %d\n", printf("u : Hello %u", INT_MIN));
	printf(" | ft_pri : %d\n", ft_printf("x : Hello %x", INT_MIN));
	printf(" | printf : %d\n", printf("x : Hello %x", INT_MIN));
	printf(" | ft_pri : %d\n", ft_printf("X : Hello %X", INT_MIN));
	printf(" | printf : %d\n", printf("X : Hello %X", INT_MIN));
	printf(" | ft_pri : %d\n", ft_printf(" NULL %%", "dddddd"));
	//printf(" | printf : %d\n", printf(" NULL %%", "dddddd"));
	printf("%d", ft_printf(0));
	printf("%d", printf(0));
	
	return (0);
}
*/