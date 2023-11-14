/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:49:27 by susajid           #+#    #+#             */
/*   Updated: 2023/11/15 11:27:02 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(int *count, unsigned long long n,
	unsigned long long base, char replace_c)
{
	char	digit;

	if (n >= base)
		ft_print_unsigned(count, n / base, base, replace_c);
	if (*count < 0)
		return ;
	digit = (n % base) + '0';
	if (replace_c && digit > '9')
		digit = digit - '9' + replace_c - 1;
	ft_print_chars(count, &digit, 1);
}
