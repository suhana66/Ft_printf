/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:06:07 by susajid           #+#    #+#             */
/*   Updated: 2023/11/14 15:50:55 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	ft_print_unsigned(int *count, unsigned long long n,
			unsigned long long base, char replace_c);
void	ft_print_chars(int *count, char *s, int len);
void	ft_print_int(int *count, int n, int sign);

#endif /* FT_PRINTF_H */
