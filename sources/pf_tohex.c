/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:56:49 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/21 14:08:55 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	pf_tohex(t_flag *flag)
{
	char			*hex;
	unsigned int	value;
	unsigned int	size;

	value = va_arg(flag->flags, unsigned int);
	if (flag->dot && value == 0 && flag->precision == 0)
		hex = ft_strdup("");
	else
		hex = flag->type == 'X' ? ft_itoa16(value, "0123456789ABCDEF") :
			ft_itoa16(value, "0123456789abcdef");
	if (!hex)
		return (0);
	if (flag->precision <= (int)ft_strlen(hex))
		size = ft_strlen(hex);
	else
		size = flag->precision;
	if (flag->width && !flag->minus)
		put_field(flag, size, ((flag->dot && flag->precision > -1) ? 0 : 1));
	pf_precision(flag, ft_strlen(hex));
	pf_str(flag, hex, size);
	if (flag->width && flag->minus)
		put_field(flag, size, 0);
	free(hex);
	return (1);
}
