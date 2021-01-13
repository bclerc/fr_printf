/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:56:49 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/13 17:06:32 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putstr_up(t_flag *flag, char *str, int maj)
{
	int		i;
	char	c;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		if (maj)
			write(1, &str[i], 1);
		else
		{
			c = ft_tolower(str[i]);
			pf_write(flag, c);
		}
		i++;
	}
}

int			pf_tohex(t_flag *flag)
{
	char *hex;

	if (!(hex = ft_itoa_base(va_arg(flag->flags, unsigned int), 16)))
		return (0);
	if (flag->width && !flag->minus)
		put_field(flag, ft_strlen(hex));
	if (flag->type == 'x')
		ft_putstr_up(flag, hex, 0);
	if (flag->type == 'X')
		ft_putstr_up(flag, hex, 1);
	if (flag->width && flag->minus)
		put_field(flag, ft_strlen(hex));
	free(hex);
	return (1);
}
