/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_narrator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:29:21 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/28 16:55:50 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_narrator(int id, int phrase, t_data *data)
{
	unsigned long	time;

	time = ft_time() - data->begin;
	pthread_mutex_lock(&data->narrator);
	if (phrase == 1)
		printf("%lu %d has taken a fork\n", time, id);
	else if (phrase == 2)
		printf("%lu %d is eating\n", time, id);
	else if (phrase == 3)
		printf("%lu %d is sleeping\n", time, id);
	else if (phrase == 4)
		printf("%lu %d is thinking\n", time, id);
	else if (phrase == 5)
		printf("%lu %d died\n", time, id);
	else if (phrase == 6)
		printf("%lu philos ate at least %d\n",
			time, data->philos[id - 1].nbrmeals);
	pthread_mutex_unlock(&data->narrator);
}
