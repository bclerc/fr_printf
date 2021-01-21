/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:33:20 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/21 14:16:05 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_field(t_flag *flag, int value_length, int zero)
{
	int i;

	if (!value_length)
		i = flag->width;
	else
		i = flag->width - value_length;
	if (flag->zero && !flag->minus && !(value_length > flag->width) && zero)
	{
		while (i > 0)
		{
			flag->total++;
			write(1, "0", 1);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			flag->total++;
			write(1, " ", 1);
			i--;
		}
	}
}

void	pf_str(t_flag *flag, char *str, int length)
{
	int i;

	i = 0;
	while (str[i] && i < (length))
	{
		flag->total++;
		write(1, &str[i], 1);
		i++;
	}
}

void	pf_write(t_flag *flag, char c)
{
	flag->total++;
	ft_putchar(c);
}

int		pf_precision(t_flag *flag, int value_length)
{
	int i;

	if (!flag->dot)
		return (0);
	i = flag->precision - value_length;
	if (flag->dot && !((value_length) > flag->precision))
	{
		while (i > 0)
		{
			flag->total++;
			write(1, "0", 1);
			i--;
		}
	}
	return (1);
}
