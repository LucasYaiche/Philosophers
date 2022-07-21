/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:57:18 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/28 16:51:13 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_dead(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = data->philos;
	while (data->death == 0)
	{
		i = -1;
		while (++i < data->nbr_philo)
		{
			if (ft_time() - philos[i].last > data->ttd)
			{
				ft_narrator(philos[i].id, 5, data);
				pthread_mutex_lock(&data->narrator);
				data->death = 1;
				return ;
			}
		}
		if (data->notepme && philos[data->nbr_philo - 1].nbrmeals
			== data->notepme)
		{
			ft_narrator(philos[data->nbr_philo - 1].id, 6, data);
			pthread_mutex_lock(&data->narrator);
			return ;
		}
	}
}
