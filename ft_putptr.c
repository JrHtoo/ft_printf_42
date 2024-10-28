/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:35:39 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/09/04 16:32:27 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	generate_ptr(uintptr_t ptr)
{
	int	printf_len;

	printf_len = 0;
	if (ptr >= 16)
	{
		printf_len += generate_ptr(ptr / 16);
		printf_len += generate_ptr(ptr % 16);
	}
	else
		printf_len += ft_putchar(LOWER_HEX[ptr]);
	return (printf_len);
}

int	ft_putptr(uintptr_t ptr)
{
	int		printf_len;

	printf_len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	else
	{
		printf_len += ft_putstr("0x");
		printf_len += generate_ptr(ptr);
	}
	return (printf_len);
}
