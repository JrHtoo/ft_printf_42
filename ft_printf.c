/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:47:49 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/09/17 13:23:05 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		printf_len;
	va_list	vlist;

	if (!str)
		return (-1);
	va_start(vlist, str);
	i = 0;
	printf_len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			printf_len += ft_printf_format(vlist, str[i + 1]);
			i++;
		}
		else
			printf_len += ft_putchar(str[i]);
		i++;
	}
	va_end(vlist);
	return (printf_len);
}
