/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:48:18 by bclerc            #+#    #+#             */
/*   Updated: 2020/09/02 14:52:26 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

int pf_putstr(t_flag *flag)
{
    int i;
    char *tmp;
    
    if (!flag || !flag->flags)
        return (0);
    tmp = va_arg(flag->flags, char*);
    i = 0;
    while (tmp[i])
    {
        ft_putchar(tmp[i]);
        i++;   
    }
    return (1);
}
