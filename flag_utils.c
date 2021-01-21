/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:48:21 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/21 14:22:12 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	set_width(t_flag *flag, char *args, int i)
{
	while (ft_isdigit(args[i]))
	{
		flag->width = (flag->width * 10) + (args[i] - '0');
			i++;
	}
	return (i);
}

int	set_width_star(t_flag *flag, int i)
{
	flag->width = va_arg(flag->flags, int);
	if (flag->width < 0)
	{
		flag->width = -flag->width;
		flag->minus = 1;
	}
	i++;
	return (i);
}

int set_precision(t_flag *flag, char *args, int i)
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
	return (i);
}

int	get_flag(t_flag *flag, char *args, int i)
{
	while (1)
	{
		if (args[i] == '-')
			flag->minus = 1;
		else if (args[i] == '0')
			flag->zero = 1;
		else
			break ;
		i++;
	}
	return (i);
}