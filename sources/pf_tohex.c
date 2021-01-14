/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:56:49 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/14 16:13:59 by bclerc           ###   ########.fr       */
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

char		*ft_itoa16(long long int value)
{
	static char		hex[] = "0123456789ABCDEF";
	char			*tab;
	long long	int len;
	
	len = get_len(value);
	if (!(tab = ft_strnew((len))))
		return (NULL);
	while (len - 1 >= 0)
	{
			tab[len - 1] = hex[value % 16];
		value /= 16;
		len--;
	}
	return (tab);
}

int			pf_precision(t_flag *flag, int value_length)
{
	int i;

	if (!flag->dot)
		return (0);
	i = flag->precision - value_length;	
	if (flag->dot && !((value_length) > flag->precision))
	{
		while (i > 0)
		{
			flag->total++;
			write(1, "0", 1);
			i--;
		}
	}
	return (1);
}


int			pf_tohex(t_flag *flag)
{
	char *hex;
	unsigned int value;
	unsigned int length;
	unsigned int size;
	
	length = 0;
	value = va_arg(flag->flags, unsigned int);
	if (value == 0)
		hex = ft_strdup("");
	else
		hex = ft_itoa16(value);
	if (flag->precision <= ft_strlen(hex))
		size = ft_strlen(hex);
	else
		size = (size + flag->precision);
	if (flag->width && !flag->minus)
		put_field(flag, size, 0);
	pf_precision(flag, ft_strlen(hex));
	pf_str(flag, hex, size);
	if (flag->width && flag->minus)
		put_field(flag, size, 0);

	return (1);
}
