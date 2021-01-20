/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:38:17 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/20 14:32:08 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	pf_address(t_flag *flag)
{
	size_t			*address;
	char			*hex;
	unsigned int	size;

	address = va_arg(flag->flags, size_t*);
	if (!address && flag->dot && flag->precision == 0)
		hex = ft_strdup("");
	else
		hex = ft_itoa16((long long int)address, "0123456789abcdef");
	if (!hex)
		return (0);
	size = ft_strlen(hex) + 2;
	if (flag->width && !flag->minus)
		put_field(flag, size, 0);
	pf_str(flag, "0x", 2);
	pf_str(flag, hex, size - 2);
	if (flag->width && flag->minus)
		put_field(flag, size, 0);
	free(hex);
	return (1);
}
