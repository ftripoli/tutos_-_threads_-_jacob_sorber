/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_with_slow_threads.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftripoli <ftripoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:34:07 by ftripoli          #+#    #+#             */
/*   Updated: 2025/06/16 19:34:46 by ftripoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

#define BIG 1000000000UL

uint32_t		g_counter = 0;
pthread_mutex_t	g_lock = PTHREAD_MUTEX_INITIALIZER;

void	*count_to_big(void *arg)
{
	uint32_t	i;

	i = 0;
	while (i < BIG)
	{
		pthread_mutex_lock(&g_lock);
		g_counter++;
		pthread_mutex_unlock(&g_lock);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	t;

	pthread_create(&t, NULL, count_to_big, NULL);
	count_to_big(NULL);
	pthread_join(t, NULL);
	printf("Done. Counter = %u\n", g_counter);
}
