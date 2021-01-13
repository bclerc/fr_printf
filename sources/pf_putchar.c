/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:01:10 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/13 17:21:53 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

void    pf_putchar(t_flag *flag)
{
    char c;

    c = va_arg(flag->flags, int);
	if (flag->width && !flag->minus)
		put_field(flag, 1);
	pf_write(flag, c);
	if (flag->width && flag->minus)
		put_field(flag, 1);

}
