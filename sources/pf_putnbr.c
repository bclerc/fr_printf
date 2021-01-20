/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:46:09 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/20 15:43:43 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

void			pf_putnbr_f(t_flag *flag, long long i)
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

int				cant_print_m(t_flag *flag, int length)
{
	if ((flag->zero && flag->width > length && !flag->dot))
		return (1);
	else if (flag->precision < 0 && flag->zero)
		return (1);
	return (0);
}

int				check_precisions(t_flag *flag, int value)
{
	if (flag->dot && value < ft_abs(flag->precision) && flag->precision > -1)
		return (1);
	return (0);
}

void			display(t_flag *flag, int l, int minus, int value)
{
	if (flag->width && !flag->minus)
		put_field(flag, l, ((flag->dot && flag->precision > -1) ? 0 : 1));
	if (flag->neg && !minus)
		pf_write(flag, '-');
	pf_precision(flag, get_number_lenght(ft_abs(value)));
	if (!(flag->dot && value == 0 && flag->precision == 0))
		pf_putnbr_f(flag, ft_abs(value));
	if (flag->width && flag->minus)
		put_field(flag, l, 0);
}

void			pf_putnbr(t_flag *flag)
{
	long long	abs_value;
	int			value;
	int			minus;
	int			length;

	minus = 0;
	value = va_arg(flag->flags, int);
	abs_value = ft_abs(value);
	flag->neg = value < 0 ? 1 : 0;
	if (check_precisions(flag, get_number_lenght(abs_value)))
		length = ft_abs(flag->precision);
	else
		length = get_number_lenght(abs_value);
	if (flag->neg)
		length++;
	if (flag->neg && cant_print_m(flag, length))
	{
		minus = 1;
		pf_write(flag, '-');
	}
	if (flag->dot && flag->precision == 0 && value == 0)
		length--;
	display(flag, length, minus, value);
}
