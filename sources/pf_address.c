/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:38:17 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/11 12:31:40 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void print_hex(intptr_t address)
{
	const char hex[] = "0123456789abcdef";
	if (address < 16)
		ft_putstr("0x");
	if (address >= 16)
		print_hex(address / 16);	
	ft_putchar(hex[address % 16]);
}

int pf_address(t_flag *flag)
{
	void		*address;

	address = va_arg(flag->flags, void*);	
	print_hex((intptr_t)address);

	return (1);
}
