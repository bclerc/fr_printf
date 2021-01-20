/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:48:18 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/20 14:42:50 by bclerc           ###   ########.fr       */
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
	tmp = !str ? ft_strdup("(null)") : ft_strdup(str);
	if (!tmp)
		return (0);
	i = 0;
	length = 0;
	if (flag->dot && ft_strlen(tmp) > flag->precision && flag->precision > -1)
		length = flag->precision;
	else
		length = ft_strlen(tmp);
	if (flag->width && !flag->minus)
		put_field(flag, length, 1);
	pf_str(flag, tmp, length);
	if (flag->width && flag->minus)
		put_field(flag, length, 1);
	free(tmp);
	return (1);
}
