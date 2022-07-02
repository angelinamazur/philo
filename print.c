/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:50:11 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/02 21:02:51 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_info(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->env->mute_print);
	printf("%lu %d %s\n", get_time() - philo->env->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->env->mute_print);
}