/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:48:18 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/13 18:27:46 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	pf_putstr(t_flag *flag)
{
	int		i;
	int		length;
	char	*tmp;
	char	*str;

	if (!flag)
		return (0);
	str = va_arg(flag->flags, char*);
	if (!str)
	{
		if (!(tmp = ft_strdup("(null)")))
			return (0);
	}
	else
	{
		if (!(tmp = ft_strdup(str)))
			return (0);
	}
	i = 0;
	length = 0;
	if (flag->dot && ft_strlen(tmp) > flag->precision && flag->precision > -1)
		length = flag->precision;
	else
		length = ft_strlen(tmp);
	if (flag->width && !flag->minus)
		put_field(flag, length);
	pf_str(flag, tmp, length);
	if (flag->width && flag->minus)
		put_field(flag, length);
	free(tmp);
	return (1);
}
