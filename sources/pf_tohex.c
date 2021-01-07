/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:56:49 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/07 12:06:29 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

int pf_tohex(t_flag *flag)
{
	char *hex;

	if (flag->type == 'x')
	{
		if (!(hex = ft_itoa_base(va_arg(flag->flags, int), 16, 0)))
			return (0);
	}
	if (flag->type == 'x')
	{
		if (!(hex = ft_itoa_base(va_arg(flag->flags, int), 16, 1)))
			return (0);
	}
	ft_putstr(hex);
	free(hex);
	return (1);
}
