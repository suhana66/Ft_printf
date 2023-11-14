/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:32:19 by susajid           #+#    #+#             */
/*   Updated: 2023/11/15 11:10:37 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_chars(int *count, char *s, int len)
{
	if (!s)
		s = "(null)";
	while ((len < 0 && *s) || len > 0)
	{
		if (write(1, s, 1) < 0)
		{
			*count = -1;
			return ;
		}
		(*count)++;
		len--;
		s++;
	}
}
