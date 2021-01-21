/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:24:55 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/21 14:10:26 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	flags_destroyer(t_flag *flag)
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

int	function_dispatcher(t_flag *flag)
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
		return (0);
	pt(flag);
	return (1);
}

int	flags_initialsizer(char *args, t_flag *flag)
{
	int i;

	i = 0;
	flags_destroyer(flag);
	while (args[i])
	{
		i = get_flag(flag, args, i);
		if (ft_isdigit(args[i]))
			i = set_width(flag, args, i);
		else if (args[i] == '*')
			i = set_width_star(flag, args, i);
		if (args[i] == '.')
			i = set_precision(flag, args, i);
		i++;
	}
	flag->args = args;
	flag->type = args[ft_strlen(args) - 1];
	function_dispatcher(flag);
	return (i);
}

int	get_format(t_flag *flag, int i)
{
	char	*str;

	if (!(str = ft_strsdup(&flag->formats[i], "bcspdiuxX%")))
		return (0);
	flags_initialsizer(str, flag);
	i = i + (ft_strlen(str));
	free(str);
	return (i);
}

int	ft_printf(char *text, ...)
{
	t_flag	flag;
	int		i;

	flag.total = 0;
	flag.formats = ft_strdup(text);
	va_start(flag.flags, text);
	i = 0;
	while (flag.formats[i])
	{
		if (flag.formats[i] == '%')
		{
			i++;
			i = get_format(&flag, i);
			continue;
		}
		if (flag.formats[i])
			pf_write(&flag, flag.formats[i]);
		i++;
	}
	if (!flag.formats)
		return (-1);
	free(flag.formats);
	va_end(flag.flags);
	return (ft_abs(flag.total));
}
