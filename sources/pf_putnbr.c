/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:46:09 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/13 18:50:57 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_putunbr(unsigned int z)
{
	if (z >= 10)
		ft_putnbr(z / 10);
	ft_putchar((z % 10) + 48);
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
	unsigned int	z;
	int				i;
	int				b;
	int				a;

	i = va_arg(flag->flags, int);
	b = ft_abs(i);
	a = get_number_lenght(b);
	if (i < 0)
	{
		if (flag->zero)
		{
			i = -i;
			ft_putchar('-');
		}
		a++;
	}
	if (flag->width && !flag->minus)
		put_field(flag, a);
	flag->total+= a;
	ft_putnbr(i);
	if (flag->width && flag->minus)
		put_field(flag, a);
}

void			pf_putunbr(t_flag *flag)
{
	unsigned int i;
	unsigned int b;

	b = va_arg(flag->flags, unsigned int);
	i = get_number_lenght(b);
	if (flag->width && !flag->minus)
		put_field(flag, i);
	flag->total+= i;
	ft_putunbr(b);
	if (flag->width && flag->minus)
		put_field(flag, i);
}
