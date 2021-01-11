/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:56:49 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/07 15:41:30 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "../includes/ft_printf.h"

static void	ft_putstr_up(char *str, int maj)
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
			write(1, &c, 1);
		}
		i++;
	}
}

int			pf_tohex(t_flag *flag)
{
	char *hex;

	if (flag->type == 'x')
	{
		if (!(hex = ft_itoa_base(va_arg(flag->flags, int), 16)))
			return (0);
		ft_putstr_up(hex, 0);
	}
	if (flag->type == 'X')
	{
		if (!(hex = ft_itoa_base(va_arg(flag->flags, int), 16)))
			return (0);
		ft_putstr_up(hex, 1);
	}
	free(hex);
	return (1);
}
