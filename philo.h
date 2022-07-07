/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:31:55 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/07 21:07:03 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef pthread_mutex_t t_mutex;
typedef struct s_philo t_philo;

typedef struct s_env
{
	int				number;
	unsigned long	start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat_each;
	t_mutex			mute_print;
	t_mutex			mute_last_eating;
	t_mutex			mute_signal;
	t_mutex			*fork;
	t_philo			*philo;

}	t_env;

typedef struct s_philo
{
	int				id;
	int				meals;
	int				signal;
	pthread_t		thread;
	t_mutex			*right;
	t_mutex			*left;
	unsigned long	last_eating;
	t_env			*env;

}	t_philo;



t_philo			*philos_init(t_env *env);
int				env_init(t_env *env, int argc, char **argv);
long long		ft_atoi(const char *str);
unsigned long	get_time(void);
void			print_info(t_philo *philo, char *msg);
void			clean_all(t_env *env);
void			ft_usleep(int time_to_wait);
void			*ft_philo(void *data);
int				check_args(int argc, char **argv);
int				ft_strcmp(char *s1, char *s2);

#endif