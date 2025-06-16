/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_return_variable_from_thread.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftripoli <ftripoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:30:59 by ftripoli          #+#    #+#             */
/*   Updated: 2025/06/16 19:31:00 by ftripoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*myturn(void *arg)
{
	int	*iptr;
	int	i;

	iptr = (int *)malloc(sizeof(int));
	*iptr = 5;
	i = 0;
	while (i < 8)
	{
		sleep(1);
		printf("my Turn ! %d\n", *iptr);
		(*iptr)++;
		i++;
	}
	return (iptr);
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
	int			*result;

	pthread_create(&newthread, NULL, myturn, NULL);
	yourturn();
	pthread_join(newthread, &result);
	printf("thread's done: *result=%d\n", *result);
}
