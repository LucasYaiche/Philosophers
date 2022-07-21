/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:22:31 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/19 14:09:17 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	arg_error(void)
{
	ft_putstr_error("argument error.\nTry : \n./philo");
	ft_putstr_error(" [nbr of philosophers] [time to die] ");
	ft_putstr_error("[time to eat] [time to sleep] ");
	ft_putstr_error("[nbr of times each philo must eat]\n");
}
