/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:37:28 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/09/04 16:32:12 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	generate_len(unsigned int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static char	*ft_uitoa(unsigned int num)
{
	int		i;
	int		len;
	char	*str;

	len = generate_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	str[i] = '0';
	str[len] = '\0';
	while (num > 0)
	{
		str[len - i - 1] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	return (str);
}

int	ft_putunbr(unsigned int num)
{
	int		printf_len;
	char	*str;

	printf_len = 0;
	str = ft_uitoa(num);
	printf_len += ft_putstr(str);
	free(str);
	return (printf_len);
}
