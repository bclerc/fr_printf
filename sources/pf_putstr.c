/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:48:18 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/12 10:08:34 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

int pf_putstr(t_flag *flag)
{
    int i;
    char *tmp;
    
    if (!flag)
        return (0);
    tmp = va_arg(flag->flags, char*);
    i = 0;

	if (flag->width && !flag->minus)
		put_field(flag, ft_strlen(tmp));
	write(1, tmp, ft_strlen(tmp));
	if (flag->width && flag->minus)
		put_field(flag, ft_strlen(tmp));
    return (1);
}
