/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:37:20 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/22 11:40:37 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch(t_data *data)
{
	int	i;

	data->begin = ft_time();
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_create(&data->philos[i].thrd_id, NULL, routine, &data->philos[i]))
			return (0);
		i++;
	}
	// check_dead(data);
	return (0);
}	
