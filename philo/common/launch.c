/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:37:20 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/28 16:53:37 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch(t_data *data)
{
	int	i;

	i = -1;
	data->begin = ft_time();
	while (++i < data->nbr_philo)
	{
		data->philos[i].last = ft_time();
		if (pthread_create(&data->philos[i].thrd_id, NULL,
				routine, &data->philos[i]))
		{
			cleanthreads(data, i);
			return (0);
		}	
	}
	check_dead(data);
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_detach(data->philos[i].thrd_id))
			return (0);
		i++;
	}
	cleanforks(data, data->nbr_philo - 1);
	free(data->philos);
	return (1);
}
