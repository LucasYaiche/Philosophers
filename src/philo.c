/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:44:19 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/14 18:08:42 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine()
{
	printf("salut\n");
	return (0);
}

int	main(int argc, char **argv)
{	
	if (argc < 5 || argc > 6)
	{
		arg_error();
		return (0);
	}
	if (!check_argv(argc--, argv++))
		return (0);
	return (0);
}
