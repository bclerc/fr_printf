/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printbinary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:44:57 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/05 11:12:15 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

void pf_printbinary(t_flag *flag)
{

    char *set;
    int i;
    int p;

    set = va_arg(flag->flags, char *);
    if (!set[1])
        return ;
    p = 0;
    while (set[p])
    {
        i = 7;
        while (i >= 0)
        {
            (set[p] & 1 << i) ? ft_putchar('1') : ft_putchar('0');
            i--;
        }
        p++;   
    }
}



