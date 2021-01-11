/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:38:17 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/11 12:29:30 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void print_hex(intptr_t address)
{
	const char hex[] = "0123456789abcdef";
	const int base = 16;

	if (address < base)
		ft_putstr("0x");
	if (address >= base)
		print_hex(address / base);	

	ft_putchar(hex[address % base]);
}

int pf_address(t_flag *flag)
{
	void		*address;

	address = va_arg(flag->flags, void*);	
	print_hex((intptr_t)address);

	return (1);
}
