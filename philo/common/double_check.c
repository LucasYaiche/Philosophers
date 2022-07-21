/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:16:12 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/19 18:47:41 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	double_check(char **argv, t_data *data)
{
	if (ft_strlen(argv[1]) != nbr_len(data->nbr_philo))
		return (0);
	if (ft_strlen(argv[2]) != nbr_len(data->ttd))
		return (0);
	if (ft_strlen(argv[3]) != nbr_len(data->tte))
		return (0);
	if (ft_strlen(argv[4]) != nbr_len(data->tts))
		return (0);
	if (argv[5] && ft_strlen(argv[5]) != nbr_len(data->notepme))
		return (0);
	if (data->nbr_philo < 0)
		return (0);
	if (data->ttd < 0)
		return (0);
	if (data->tte < 0)
		return (0);
	if (data->tts < 0)
		return (0);
	if (argv[5] && data->notepme < 0)
		return (0);
	return (1);
}
