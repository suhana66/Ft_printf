/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:14:59 by susajid           #+#    #+#             */
/*   Updated: 2023/11/15 12:02:39 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_format(int *result, char *s, va_list args);

int	ft_printf(const char *s, ...)
{
	int		result;
	va_list	args;

	result = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (!*s)
				break ;
			print_format(&result, (char *)s, args);
		}
		else
			ft_print_chars(&result, (char *)s, 1);
		if (result < 0)
			break ;
		s++;
	}
	va_end(args);
	return (result);
}

static void	print_format(int *result, char *s, va_list args)
{
	long long	var;

	if (*s == 'c')
	{
		var = va_arg(args, int);
		ft_print_chars(result, (char *)&var, 1);
	}
	else if (*s == 's')
		ft_print_chars(result, va_arg(args, char *), -1);
	else if (*s == 'p')
	{
		ft_print_chars(result, "0x", -1);
		ft_print_unsigned(result, va_arg(args, unsigned long long), 16, 'a');
	}
	else if (*s == 'd' || *s == 'i')
		ft_print_int(result, va_arg(args, int), 0);
	else if (*s == 'u')
		ft_print_unsigned(result, va_arg(args, unsigned int), 10, 0);
	else if (*s == 'x')
		ft_print_unsigned(result, va_arg(args, unsigned int), 16, 'a');
	else if (*s == 'X')
		ft_print_unsigned(result, va_arg(args, unsigned int), 16, 'A');
	else if (*s == '%')
		ft_print_chars(result, s, 1);
}

// #include <stdio.h>
// #include <limits.h>
// int main(void)
// {
//     int res;

// 	// TEST 1
// 	ft_printf("%d\n", -2147483647);
// 	printf("%d\n", -2147483647);

// 	// TEST 2
// 	ft_printf("%s\n", NULL);
// 	printf("%s\n", NULL);

// 	// TEST 3
// 	ft_printf("%p\n", NULL);
// 	printf("%p\n", NULL);

// 	// TEST 4
// 	char *s = "hello";
// 	ft_printf("%p\n", s);
// 	printf("%p\n", s);

// 	// TEST 5
// 	ft_printf("%s\n", s);
// 	printf("%s\n", s);

// 	// TEST 6
// 	ft_printf("%s\t%i\n", s, 42);
// 	printf("%s\t%i\n", s, 42);

// 	// TEST 7
// 	ft_printf("%x\n", 42);
// 	printf("%x\n", 42);

// 	// TEST 8
// 	ft_printf("%x\n", 0xfafa);
// 	printf("%x\n", 0xfafa);

// 	// TEST 9
// 	ft_printf("%X\n", 0xfafa);
// 	printf("%X\n", 0xfafa);

// 	// TEST 10
// 	ft_printf("%i\n", 0xfafa);
// 	printf("%i\n", 0xfafa);

// 	// TEST 11
// 	ft_printf("%c\n", 'a');
// 	printf("%c\n", 'a');

// 	// TEST 12
// 	ft_printf("%d\n", 0xfafa);
// 	printf("%d\n", 0xfafa);

// 	// TEST 13
// 	res = ft_printf(" %c %c %c ", '0', 0, '1');
// 	printf("%d\n", res);
// 	res = printf(" %c %c %c ", '0', 0, '1');
// 	printf("%d\n", res);

// 	// TEST 14
// 	res = ft_printf("%d\n", -8990000990990);
// 	printf("%d\n", res);
// 	res = printf("%d\n", -8990000990990);
// 	printf("%d\n", res);

// 	// TEST 15
// 	res = ft_printf("%d\n", LLONG_MAX);
// 	printf("%d\n", res);
// 	res = printf("%d\n", LLONG_MAX);
// 	printf("%d\n", res);

// 	return (0);
// }