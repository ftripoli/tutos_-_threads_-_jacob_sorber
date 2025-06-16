/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_without_threads.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftripoli <ftripoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:32:51 by ftripoli          #+#    #+#             */
/*   Updated: 2025/06/16 19:33:07 by ftripoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

#define BIG 1000000000UL

uint32_t	g_counter = 0;

void	count_to_big(void)
{
	uint32_t	i;

	i = 0;
	while (i < BIG)
	{
		g_counter++;
		i++;
	}
}

int	main(void)
{
	count_to_big();
	count_to_big();
	printf("Done. Counter = %u\n", g_counter);
}
