/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:24:55 by bclerc            #+#    #+#             */
/*   Updated: 2020/10/26 13:14:44 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

int flags_destroyer(t_flag *flag)
{
    free(flag->args);
}

int flags_initialsizer(char *args, t_flag *flag)
{
    int i;

    while (args[i])
    {
        if (args[i] == '-')
            flag->minus = 1;
        if (args[i] == '0')
            flag->zero = 1;
        if (args[i] == '*')
            flag->width = va_arg(flag->flags, int);
        while (ft_isdigit(args[i]) && !flag->width)
        {
            flag->width = flag->width + (ft_todigit(args[i]) * 10);
            i++;
        }
        i++;
    }
    printf("\n Flags - : %d\n Flags 0 = %d \n Taille de champs . %d \n", flag->minus, flag->zero, flag->width);
    flag->args = args;
    flag->type = args[ft_strlen(args) - 1];
    function_dispatcher(flag);
    return (ft_strlen(args));
}

int function_dispatcher(t_flag *flag)
{
        void (*pt)(*t_flag);

        if (flag->type == 's')
         pt = &pf_putstr;
        else if (flag->type == 'd')
         pt = &pf_putnbr;
        else if (flag->type == 'c')
         pt = &pf_putchar;
        else if (flag->type == 'b')
         pt = &pf_printbinary;
        else
        {
            printf("rien pelo");
            return 0;
        }
        pt(flag);
        flags_destroyer(flag);
        return (1);
}

void ft_printf(char* text, ...)
{
    char *format;
    t_flag flag;
    int i;

    format = ft_strdup(text);
    va_start(flag.flags, text);

    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
            i = i + flags_initialsizer(ft_strsdup(&format[i], "cfbdts"), &flag);
        ft_putchar(format[i]);
        i++;
    }
    va_end(flag.flags);

}

int main(void)
{


    ft_printf("Test de message  : %-50d", 12);

}
