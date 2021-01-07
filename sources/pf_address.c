/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:38:17 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/07 15:37:08 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int pf_address(t_flag *flag)
{
	char *tmp;
	unsigned long long c;

	c = (unsigned long long)va_arg(flag->flags, unsigned long long);
	
	printf("%llu <<<<<<",c);
	tmp = ft_itoa_base((unsigned long long) c, 16);
	ft_putstr(tmp);
	free(tmp);
}