/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:31:37 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/14 18:05:58 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>


// typedef struct s_philo
// {
// 	/* data */
// }				t_philo;


/*======*/
/* check*/
/*======*/

int		check_argv(int argc, char **argv);

/*======*/
/* error*/
/*======*/

void	arg_error(void);

/*======*/
/* utils*/
/*======*/

size_t	ft_strlen(const char *str);
int	ft_isdigit(int str);

/*========*/
/* put_str*/
/*========*/

void	ft_putstr_error(char *s);

#endif