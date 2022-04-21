/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:34:32 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/21 16:51:11 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo 		*philo;
	t_data			*data;
	unsigned long	time;

	philo = arg;
	data = philo->data;
	time = ft_time() - data->begin;
	pthread_mutex_unlock(&data->narrator);
	printf("%lu %d has taken a fork\n", time, philo->id);
	printf("%lu %d is eating\n", time, philo->id);
	printf("%lu %d is sleeping\n", time, philo->id);
	printf("%lu %d is thinking\n", time, philo->id);
	pthread_mutex_lock(&data->narrator);
	return (0);
}
