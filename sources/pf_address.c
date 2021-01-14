/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:38:17 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/14 14:25:13 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void print_hex(t_flag *flag, intptr_t address)
{
	const char hex[] = "0123456789abcdef";
	if (address < 16)
		pf_str(flag, "0x", 2);
	if (address >= 16)
		print_hex(flag, address / 16);	
	pf_write(flag, hex[address % 16]);
}

int pf_address(t_flag *flag)
{
	void		*address;

	address = va_arg(flag->flags, void*);	
	print_hex(flag, (intptr_t)address);

	return (1);
}
