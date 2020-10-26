/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:46:09 by bclerc            #+#    #+#             */
/*   Updated: 2020/09/02 15:51:27 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

void	pf_putnbr(t_flag *flag)
{
	unsigned int z;
    int i;

    i = va_arg(flag->flags, int);

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
