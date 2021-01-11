/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:24:55 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/11 11:55:50 by bclerc           ###   ########.fr       */
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
    flag->asterisk = 0;

}

int flags_initialsizer(char *args, t_flag *flag)
{
	printf("Longueur : %d", flag->width);
    int i;
    i = 1;
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
			i++;
		}
		if (args[i] == '.')
		{
			i++;
			if (ft_isdigit(args[i]))
			{
				while (ft_isdigit(args[i]))
				{
					flag->dot = (flag->dot * 10) + (args[i] - '0');
					i++;
				}
			}
			else if (args[i] == '*')
			{
				flag->dot = va_arg(flag->flags, int);
				i++;
			}
		}
		i++;
	}

    printf("\n===\nArgument : %s\n Flags - : %d\n Flags 0 : %d\n Précision : %d \n Taille de champs : %d \n", args, flag->minus, flag->zero, flag->dot, flag->width);
    flag->args = args;
    flag->type = args[ft_strlen(args) - 1];
	printf("Flag type : %c\n", flag->type);
    function_dispatcher(flag);
    return (i);
}

int function_dispatcher(t_flag *flag)
{
        void (*pt)(*t_flag);

        if (flag->type == 's')
         pt = &pf_putstr;
        else if (flag->type == 'd' || flag->type == 'i')
         pt = &pf_putnbr;
		else if (flag->type == 'u')
         pt = &pf_putunbr;
        else if (flag->type == 'c')
         pt = &pf_putchar;
        else if (flag->type == 'b')
         pt = &pf_printbinary;
		else if (flag->type == 'p')
         pt = &pf_address;
		else if (flag->type == 'x' || flag->type == 'X')
         pt = &pf_tohex;
        else
        {
            printf("rien pelo");
            return 0;
        }
        pt(flag);
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
            i = i + flags_initialsizer(ft_strsdup(&format[i], "bcspdiuxX"), &flag);
        ft_putchar(format[i]);
        i++;
    }
    va_end(flag.flags);
	free(flag.args);
}

int main(int argc, char **argv)
{
	(void)argc;

	char tamer = 'a';
	ft_printf("%p\n", &tamer);
	printf("%p", &tamer);
	return (0);
}