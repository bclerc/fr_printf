/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:46:09 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/12 10:19:03 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

void	pf_putunbr(t_flag *flag)
{
	unsigned int z;
    unsigned int i;

    i = va_arg(flag->flags, unsigned int);

	if (i < 0)
	{
		ft_putchar('-');
		z = -i;
	}
	else
		z = i;
	if (z >= 10)
		ft_putnbr(z / 10);
	ft_putchar((z % 10) + 48);
}

void	pf_putnbr(t_flag *flag)
{
	unsigned int z;
    int i;
	int b;
	int a;

    i = va_arg(flag->flags, int);
	b = i;
	a = 1;
	while (b > 10)
	{
		b = b /10;
		a++;
	}
	if (flag->width && !flag->minus)
		put_field(flag, a);
	ft_putnbr(i);
	if (flag->width && flag->minus)
		put_field(flag, a);
}
