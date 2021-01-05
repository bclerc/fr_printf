/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:48:18 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/05 13:55:05 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

int ft_pad(char *str ,int length, int right, int zero)
{
	int i;
	int b;
	int z;

	b = ft_strlen(str) * length;
	i = 0;
	if (right)
		while (str[i] && i < length)
		{
			if (i > b)
			{
				z = 0;
				while (str[z])
				{
					ft_putchar(str[i]);
					z++;
				}
				return 0;
			}
			ft_putchar(' ');
			i++;
		}
	return (0);
}

int pf_putstr(t_flag *flag)
{
    int i;
    char *tmp;
    
    if (!flag)
        return (0);
    tmp = va_arg(flag->flags, char*);
    i = 0;

    if (flag->width)
    {
        write(1, tmp, flag->width);
    }
	else
	{
		write(1, tmp, ft_strlen(tmp));
	}
	

    return (1);
}
