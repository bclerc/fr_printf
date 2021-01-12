/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:33:20 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/12 12:01:58 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void put_field(t_flag *flag, int value_lenght)
{
	int i;

	i = flag->width - value_lenght;	
	if (flag->zero && !flag->minus && !(value_lenght > flag->width))
	{
		while (i > 0)
		{
			write(1, "0", 1);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			write(1, " ", 1);
			i--;
		}
	}
}
