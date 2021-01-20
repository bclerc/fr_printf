/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:52:34 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/20 14:32:48 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_percent(t_flag *flag)
{
	if (flag->width && !flag->minus)
		put_field(flag, 1, 1);
	pf_write(flag, '%');
	if (flag->width && flag->minus)
		put_field(flag, 1, 1);
}
