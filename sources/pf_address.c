/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:38:17 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/11 11:54:31 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void tohex(unsigned long address)
{
	const char hex[] = "123456789abcdef";
	
	if (address < 16)
		ft_putchar(hex[address]);
	else
	{
		tohex(address / 16);
		tohex(address % 16);
	}
}

int pf_address(t_flag *flag)
{
	void		*address;

	address = va_arg(flag->flags, void*);	
	tohex((unsigned long)address);
}
