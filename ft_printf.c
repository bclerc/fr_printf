/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:24:55 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/15 13:00:11 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

int flags_destroyer(t_flag *flag)
{
    flag->minus = 0;
    flag->type = 0;
    flag->width = 0;
    flag->minus = 0;
    flag->zero = 0;
    flag->dot = 0;
	flag->precision = 0;
    flag->asterisk = 0;
	return (1);
}

int function_dispatcher(t_flag *flag)
{
         void (*pt)(t_flag*);

        if (flag->type == 's')
         pt = (void*)&pf_putstr;
        else if (flag->type == 'd' || flag->type == 'i')
         pt = &pf_putnbr;
		else if (flag->type == 'u')
         pt = &pf_putunbr;
        else if (flag->type == 'c')
         pt = &pf_putchar;
        else if (flag->type == 'b')
         pt = &pf_printbinary;
		else if (flag->type == '%')
         pt = &pf_percent;
		else if (flag->type == 'p')
         pt = (void*)&pf_address;
		else if (flag->type == 'x' || flag->type == 'X')
         pt = (void*)&pf_tohex;
        else
        {
            //printf("rien pelo");
            return 0;
        }
        pt(flag);
        return (1);
}

int flags_initialsizer(char *args, t_flag *flag)
{
    int i;
    i = 0;
	flags_destroyer(flag);

	while (args[i])
	{
		while (1)
		{
		if (args[i] == '-')
			flag->minus = 1;
		else if (args[i] == '0')
			flag->zero = 1;
		else
			break;
		i++;
		}
		if (ft_isdigit(args[i]))
		{	
			while (ft_isdigit(args[i]))
			{
				flag->width = (flag->width * 10) + (args[i] - '0');
				i++;
			}
		}
		else if (args[i] == '*')
		{
		 	flag->width = va_arg(flag->flags, int);
			if (flag->width < 0)
			{
				flag->width = -flag->width;
				flag->minus = 1;
			}
			i++;
		}
		if (args[i] == '.')
		{
			flag->dot = 1;
			i++;
			if (ft_isdigit(args[i]))
			{
				while (ft_isdigit(args[i]))
				{
					flag->precision = (flag->precision * 10) + (args[i] - '0');
					i++;
				}
			}
			else if (args[i] == '*')
			{
				flag->precision = va_arg(flag->flags, int);
				i++;
			}
		}
		i++;
	}

    //printf("\n===\nArgument : %s\n Flags - : %d\n Flags 0 : %d\n Précision : %d \nPrécision : %d \n Taille de champs : %d \n", args, flag->minus, flag->zero, flag->dot, flag->precision, flag->width);
    flag->args = args;
    flag->type = args[ft_strlen(args) - 1];
	//printf("Flag type : %c\n", flag->type);
    function_dispatcher(flag);
    return (i);
}


int ft_printf(char* text, ...)
{
    char *format;
	char *str;

    t_flag flag;
    int i;
	int total;

	flag.total = 0;
    format = ft_strdup(text);
    va_start(flag.flags, text);

    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
		{
			i++;
			str = ft_strsdup(&format[i], "bcspdiuxX%");
			flags_initialsizer(str, &flag);
			i = i + (ft_strlen(str));
			continue;
		}
        if (format[i])
			pf_write(&flag, format[i]);
        i++;
    }
    va_end(flag.flags);
	total = flag.total;
	free(flag.args);
	return (total);
}
