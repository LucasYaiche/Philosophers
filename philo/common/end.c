/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:27:40 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/28 16:35:10 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	errorphilos(t_data *data)
{
	free(data->forks);
	return (1);
}

int	cleanforks(t_data *data, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		pthread_mutex_destroy(&data->forks[i]);
	free(data->forks);
	return (1);
}

int	cleanthreads(t_data *data, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		pthread_detach(data->philos[i].thrd_id);
	cleanforks(data, data->nbr_philo - 1);
	free(data->philos);
	return (1);
}
