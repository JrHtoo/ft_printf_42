/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:28:50 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/09/16 12:54:29 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrtohex(unsigned int num, char format)
{
	int	printf_len;

	printf_len = 0;
	if (num >= 16)
	{
		printf_len += ft_nbrtohex(num / 16, format);
		printf_len += ft_nbrtohex(num % 16, format);
	}
	else
	{
		if (format == 'x')
			printf_len += ft_putchar(LOWER_HEX[num]);
		else
			printf_len += ft_putchar(UPPER_HEX[num]);
	}
	return (printf_len);
}
