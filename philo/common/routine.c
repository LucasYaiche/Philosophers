/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:34:32 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/28 17:24:42 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

		philo = arg;
	if (philo->id % 2 == 0)
		ft_usleep(2);
	while (philo->data->death == 0)
	{
		pthread_mutex_lock(philo->lfork);
		ft_narrator(philo->id, 1, philo->data);
		pthread_mutex_lock(philo->rfork);
		ft_narrator(philo->id, 1, philo->data);
		philo->last = ft_time();
		ft_narrator(philo->id, 2, philo->data);
		if (philo->data->notepme && philo->id == philo->data->nbr_philo)
			philo->nbrmeals++;
		ft_usleep(philo->data->tte);
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		ft_narrator(philo->id, 3, philo->data);
		ft_usleep(philo->data->tts);
		ft_narrator(philo->id, 4, philo->data);
	}	
	return (0);
}
