/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:33:20 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/13 18:28:08 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void put_field(t_flag *flag, int value_length)
{
	int i;

	if (!value_length)
		i = flag->width;
	else
		i = flag->width - value_length;	
	if (flag->zero && !flag->minus && !(value_length > flag->width))
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

void pf_str(t_flag *flag, char *str, int length)
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

void pf_write(t_flag *flag, char c)
{
	flag->total++;
	ft_putchar(c);
}

void put_field_dot(t_flag *flag, int value_length)
{
	int i;

	i = flag->dot - value_length;	
	if (flag->zero && !(value_length > flag->dot))
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

