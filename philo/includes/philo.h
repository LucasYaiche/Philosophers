/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:31:37 by lyaiche           #+#    #+#             */
/*   Updated: 2022/04/28 16:53:03 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				nbrmeals;
	unsigned long	last;
	struct s_data	*data;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	pthread_t		thrd_id;

}				t_philo;

typedef struct s_data
{
	int				nbr_philo;
	unsigned long	ttd;
	unsigned long	tte;
	unsigned long	tts;
	int				notepme;
	unsigned long	begin;
	int				death;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	narrator;
}				t_data;

/*=======*/
/* check */
/*=======*/

int				check_argv(char **argv);
void			check_dead(t_data *data);
int				double_check(char **argv, t_data *data);

/*=======*/
/* error */
/*=======*/

void			arg_error(void);
int				cleanforks(t_data *data, int n);
int				cleanthreads(t_data *data, int n);
int				errorphilos(t_data *data);

/*======*/
/* main */
/*======*/

int				launch(t_data *data);
void			*routine(void	*arg);

/*=========*/
/* put_str */
/*=========*/

void			ft_putstr_error(char *s);

/*=======*/
/* utils */
/*=======*/

int				ft_atoi(const char *str);
int				ft_isdigit(int str);
void			ft_narrator(int id, int phrase, t_data *data);
size_t			ft_strlen(const char *str);
unsigned long	ft_time(void);
void			ft_usleep(unsigned long time);
size_t			nbr_len(int nbr);

#endif
