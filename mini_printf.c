/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:55:43 by user              #+#    #+#             */
/*   Updated: 2024/09/03 21:23:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#define HEX_LOWER "0123456789abcdef"
#define HEX_UPPER "0123456789ABCDEF"

int ft_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *str)
{
    int printf_len;

    if (str == NULL)
    {
        write(1, "(null)", 6);
        return (6);
    }
    printf_len = 0;
    while (str[printf_len])
    {
        write(1, &str[printf_len], 1);
        printf_len++;
    }
    return (printf_len);
}

int count_num(int num)
{
    int count;

    count = 0;
    if (num == 0)
        return (1);
    if (num == -2147483648)
        return (11);
    if (num < 0)
    {
        num *= -1;
        count++;
    }
    while (num > 0)
    {
        num = num / 10;
        count++;
    }
    return (count);
}

char    *ft_itoa(int num)
{
    int     i;
    int     len;
    char    *str;

    len = count_num(num);
    str = (char *)malloc(sizeof(char) * (len + 1));
    i = 0;
    if (num == -2147483648)
    {
        str = "–2147483648";
        return (str);
    }
    if (num == 0)
        str[0] = '0';
    if (num < 0)
    {
        num *= -1;
        str[0] = '-';
    }
    while (num > 0)
    {
        str[len - i - 1] = (num % 10) + '0';
        num = num / 10;
        i++;
    }
    return (str);
}

int ft_putnbr(int   num)
{
    int printf_len;
    char    *str;

    str = ft_itoa(num);
    printf_len = ft_putstr(str);
    free(str);
    return (printf_len);
}

int ft_putpercent(void)
{
    write(1, "%", 1);
    return (1);
}

int sizeof_ptr(uintptr_t ptr)
{
    int len;

    len = 0;
    while (ptr > 0)
    {
        ptr = ptr / 16;
        len++;
    }
    return (len);
}

char    *printptr(uintptr_t ptr)
{
    int     i;
    int     len;
    char    *str;

    len = sizeof_ptr(ptr);
    str = (char *)malloc(sizeof(char) * len);
    if (str == NULL)
        return (NULL);
    i = 0;
    while (ptr > 0 && i < len)
    {
        str[len - i - 1] = HEX_LOWER[ptr % 16];
        // printf("\n%d ==> %c", len - i - 1, str[len - i - 1]);
        ptr = ptr / 16;
        i++;
    }
    return (str);
}

int ft_putptr(unsigned long int ptr)
{
    int     printf_len;
    char    *str;

    printf_len = 0;
    printf_len += ft_putstr("0x");
    if (ptr == 0)
        printf_len += ft_putchar('0');
    else
    {
        str = printptr(ptr);
        printf_len += ft_putstr(str);
    }
    // printf("\n<<<===>>>%s\n",str);
    free(str);
    return (printf_len);
}

int ft_printf_format(va_list arg, const char format)
{
    int printf_len;

    printf_len = 0;
    if (format == 'c')
        printf_len += ft_putchar(va_arg(arg, int));
    else if (format == 's')
        printf_len += ft_putstr(va_arg(arg, char*));
    else if (format == 'd' || format == 'i')
        printf_len += ft_putnbr(va_arg(arg, int));
    else if (format == 'p')
        printf_len += ft_putptr(va_arg(arg, unsigned long int));
    else if (format == '%')
        printf_len += ft_putpercent();
    return (printf_len);
}

int ft_printf(const char *str, ...)
{
    int     i;
    int     printf_len;
    va_list vlist;
    
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

int main(void)
{
    //ft_printf("%d\n",ft_printf("%d\n%s\n%c\n%%\n", -1234, "I am a boy", '6'));
    //ft_printf("%d\n",ft_printf("%s\n", "Amen"));
    //ft_printf("%d %d %d %d %d %d %d %d %d\n", 123, 3, -345, 2147483647, 21474836, 100000, 0, 343, 231);
    int *p;
    ft_printf("%p\n", p);
    printf("%p\n", p);
    p = (int *)malloc(sizeof(int) * 4);
    ft_printf("%p\n", p);
    printf("%p\n", p);
}