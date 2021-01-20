/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:58:46 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/20 15:43:10 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_putunbr(t_flag *flag, unsigned int z)
{
	if (z >= 10)
		ft_putunbr(flag, z / 10);
	pf_write(flag, (z % 10) + 48);
}

int				check_precision(t_flag *flag, int value)
{
	if (flag->dot && value < ft_abs(flag->precision))
		return (1);
	return (0);
}

void			pf_putunbr(t_flag *flag)
{
	unsigned int value;
	unsigned int length;

	value = va_arg(flag->flags, unsigned int);
	if (check_precision(flag, get_number_lenght(value)) && flag->precision > -1)
		length = flag->precision;
	else
		length = get_number_lenght(value);
	if (flag->dot && flag->precision == 0 && value == 0)
		length--;
	if (flag->width && !flag->minus)
		put_field(flag, length, ((flag->dot && flag->precision > -1) ? 0 : 1));
	pf_precision(flag, get_number_lenght(value));
	if (!(flag->dot && value == 0 && flag->precision == 0))
		ft_putunbr(flag, value);
	if (flag->width && flag->minus)
		put_field(flag, length, 0);
}
