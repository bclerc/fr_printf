/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_math_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:28:13 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/20 15:12:44 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				get_len(long long int value)
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

unsigned int	get_number_lenght(unsigned int i)
{
	int a;

	a = 1;
	while (i >= 10)
	{
		i = i / 10;
		a++;
	}
	return (a);
}

char			*ft_itoa16(long long int value, char *base_str)
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
