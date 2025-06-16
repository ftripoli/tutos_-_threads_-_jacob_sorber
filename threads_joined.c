/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_joined.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftripoli <ftripoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:30:39 by ftripoli          #+#    #+#             */
/*   Updated: 2025/06/16 19:30:50 by ftripoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/**
 * jonning too threads is the way to tell the main that it must wait the
 * joinned thread to end before quiting
 */
void	*myturn(void *arg)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		sleep(1);
		printf("my Turn ! %d\n", i);
		i++;
	}
	return (NULL);
}

void	yourturn(void)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		sleep(2);
		printf("Your Turn ! %d\n", i);
		i++;
	}
}

int	main(void)
{
	pthread_t	newthread;

	pthread_create(&newthread, NULL, myturn, NULL);
	yourturn();
	pthread_join(newthread, NULL);
}
