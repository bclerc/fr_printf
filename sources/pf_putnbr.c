/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:46:09 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/18 15:09:53 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_putunbr(t_flag *flag, unsigned int z)
{
	if (z >= 10)
		ft_putunbr(flag, z / 10);
	pf_write(flag, (z % 10) + 48);
}

void	pf_putnbr_f(t_flag *flag, int i)
{
	unsigned int z;

	if (i < 0)
	{
		pf_write(flag, '-');
		z = -i;
	}
	else
		z = i;
	if (z >= 10)
		pf_putnbr_f(flag, z / 10);
	pf_write(flag, (z % 10) + 48);
}


unsigned int	get_number_lenght(unsigned int i)
{
	int a;

	a = 1;
	while (i >= 10)
	{
		i = i / 10;
		a++;
	}
	return (a);
}

void			pf_putnbr(t_flag *flag)
{
	int value;
	int abs_value;
	int neg;
	int minus;
	int length;

	minus = 0;
	value = va_arg(flag->flags, int);
	abs_value = ft_abs(value);
	if (value < 0)
		neg = 1;
	if (flag->dot && get_number_lenght(abs_value) + neg < ft_abs(flag->precision) && flag->precision > -1)
		length = ft_abs(flag->precision);
	else
	{
		length = get_number_lenght(abs_value);
	}
	if (neg && ((!flag->dot && flag->precision > -1) && flag->zero))
	{
		minus = 1;
		pf_write(flag, '-');
	}
	if (flag->dot && flag->precision == 0 && value == 0)
		length--;
	if (flag->width && !flag->minus)
		put_field(flag, length + neg, ((flag->dot && flag->precision > -1) ? 0 : 1 ));
	if (neg && !minus)
		pf_write(flag, '-');
	pf_precision(flag, get_number_lenght(abs_value));
	if (!(flag->dot && value == 0 && flag->precision == 0))	
		pf_putnbr_f(flag, abs_value);
	if (flag->width && flag->minus)
		put_field(flag, length + neg, 0);
}

void			pf_putunbr(t_flag *flag)
{
	unsigned int value;
	unsigned int length;

	value = va_arg(flag->flags, unsigned int);
		length = get_number_lenght(value);
	if (value == 0)
		length = 0;
	if (flag->width && !flag->minus)
		put_field(flag, length, ((flag->dot && flag->precision > -1) ? 0 : 1 ));
	pf_precision(flag, length);
	if (!(flag->dot && value == 0 && flag->precision == 0))	
		ft_putunbr(flag, value);
	if (flag->width && flag->minus)
		put_field(flag, length, 0);
}
