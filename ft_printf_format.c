/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 08:03:49 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/09/04 16:31:39 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(va_list vlist, char format)
{
	int	printf_len;

	printf_len = 0;
	if (format == 'c')
		printf_len += ft_putchar(va_arg(vlist, int));
	else if (format == 's')
		printf_len += ft_putstr(va_arg(vlist, char *));
	else if (format == 'd' || format == 'i')
		printf_len += ft_putnbr(va_arg(vlist, int));
	else if (format == 'u')
		printf_len += ft_putunbr(va_arg(vlist, unsigned int));
	else if (format == 'p')
		printf_len += ft_putptr(va_arg(vlist, uintptr_t));
	else if (format == 'x' || format == 'X')
		printf_len += ft_nbrtohex(va_arg(vlist, unsigned int), format);
	else if (format == '%')
		printf_len += ft_putpercent();
	return (printf_len);
}
