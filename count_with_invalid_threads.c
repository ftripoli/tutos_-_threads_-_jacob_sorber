/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_with_invalid_threads.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftripoli <ftripoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:33:47 by ftripoli          #+#    #+#             */
/*   Updated: 2025/06/16 19:33:58 by ftripoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

#define BIG 1000000000UL

uint32_t	g_counter = 0;

void	*count_to_big(void *arg)
{
	uint32_t	i;

	i = 0;
	while (i < BIG)
	{
		g_counter++;
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
