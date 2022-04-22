/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:34:32 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/22 13:33:52 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo 		*philo;
	unsigned long	time;

	philo = arg;
	time = ft_time() - philo->data->begin;
	pthread_mutex_unlock(&philo->data->narrator);
	printf("%lu %d has taken a fork\n", time, philo->id);
	pthread_mutex_lock(philo->lfork);
	printf("%lu %d has taken a fork\n", time, philo->id);
	pthread_mutex_lock(philo->rfork);
	philo->last = ft_time();
	printf("%lu %d is eating\n", time, philo->id);
	ft_usleep(philo->data->tte * 1000);
	printf("%lu %d is sleeping\n", time, philo->id);             
	ft_usleep(philo->data->tts * 1000);
	printf("%lu %d is thinking\n", time, philo->id);
	pthread_mutex_lock(&philo->data->narrator);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	return (0);
}
