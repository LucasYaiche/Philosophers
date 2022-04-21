/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:37:20 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/21 16:46:56 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch(t_data *data)
{
	int	i;

	data->begin = ft_time();
	i = -1;
	while (++i < data->nbr_philo)
		if (pthread_create(&data->philos[i].thrd_id, NULL, routine, &data->philos[i]))
			return (0);
	check_dead(data);
	return (0);
}	
