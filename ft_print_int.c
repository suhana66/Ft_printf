/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:01:17 by susajid           #+#    #+#             */
/*   Updated: 2023/11/15 11:28:51 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(int *count, int n, int sign)
{
	char	digit;

	if (!sign)
	{
		if (n < 0)
		{
			ft_print_chars(count, "-", 1);
			sign = -1;
		}
		else
			sign = 1;
	}
	if ((n >= 10 && sign == 1) || (n <= -10 && sign < 0))
		ft_print_int(count, n / 10, sign);
	if (*count < 0)
		return ;
	digit = n % 10 * sign + '0';
	ft_print_chars(count, &digit, 1);
}
