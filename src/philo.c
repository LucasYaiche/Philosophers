/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:44:19 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/21 14:36:22 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_value(int argc, char **argv, t_data *data)
{
	data->nbr_philo = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	if (argc == 6)
		data->notepme = ft_atoi(argv[5]);
	if(!double_check(argv, data))
	{
		arg_error();
		return (0);
	}
	return (1);
}

int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	if (!data->forks)
		return (0);
	i = -1;
	while (++i < data->nbr_philo)
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (0);
	if (pthread_mutex_init(&data->narrator, NULL))
		return (0);
	return (1);
	
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->nbr_philo);
	if (!data->philos)
		return (0);
	data->philos[0].id = 1;
	data->philos[0].nbrmeals = 0;
	data->philos[0].last = 0;
	data->philos[0].data = data;
	data->philos[0].lfork = &data->forks[data->nbr_philo - 1];
	data->philos[0].rfork = &data->forks[0];
	i = 0;
	while (++i < data->nbr_philo)
	{
		data->philos[0].id = i;
		data->philos[0].nbrmeals = 0;
		data->philos[0].last = 0;
		data->philos[0].data = data;
		data->philos[0].lfork = &data->forks[i - 1];
		data->philos[0].rfork = &data->forks[i];	
	}
	return (1);
}

int	main(int argc, char **argv)
{	
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		arg_error();
		return (0);
	}
	if (!check_argv(&argv[1]))
	{
		arg_error();
		return (0);
	}
	init_value(argc, argv, &data);
	if (!init_forks(&data))
		return (0);
	if (!init_philos(&data))
		return (0);
	if (!launch(&data))
		return (0);
	return (0);
}
