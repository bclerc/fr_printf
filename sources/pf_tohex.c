/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:56:49 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/18 15:07:06 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	get_len(long long int value)
{
	int count;

	count = 0;
	while (value >= 16)
	{
		value /= 16;
		count++;
	}
	return (count + 1);
}

char		*ft_itoa16(long long int value, char* base_str)
{
	int				base;
	char			*tab;
	long long	int len;
	
	base = ft_strlen(base_str);
	len = get_len(value);
	if (!(tab = ft_strnew((len))))
		return (NULL);
	while (len - 1 >= 0)
	{
			tab[len - 1] = base_str[value % base];
		value /= base;
		len--;
	}
	return (tab);
}

int			pf_tohex(t_flag *flag)
{
	char *hex;
	unsigned int value;
	unsigned int length;
	unsigned int size;
	
	length = 0;
	value = va_arg(flag->flags, unsigned int);
	if (flag->dot && value == 0 && flag->precision == 0)	
		hex = ft_strdup("");
	else
	{
		if (flag->type == 'X')
			hex = ft_itoa16(value, "0123456789ABCDEF");
		else	
			hex = ft_itoa16(value, "0123456789abcdef");
	}
	if (flag->precision <= (int)ft_strlen(hex))
		size = ft_strlen(hex);
	else
		size = flag->precision;
	if (flag->width && !flag->minus)
		put_field(flag, size, ((flag->dot && flag->precision > -1)? 0 : 1));
	pf_precision(flag, ft_strlen(hex));
	pf_str(flag, hex, size);
	if (flag->width && flag->minus)
		put_field(flag, size, 0);

	return (1);
}
