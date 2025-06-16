/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_send_variable_to_thread.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftripoli <ftripoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:29:04 by ftripoli          #+#    #+#             */
/*   Updated: 2025/06/16 19:29:06 by ftripoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*myturn(void *arg)
{
	int	*iptr;
	int	i;

	i = 0;
	iptr = (int *)arg;
	while (i < 13)
	{
		sleep(1);
		printf("my Turn ! %d\n", *iptr);
		(*iptr)++;
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
	int			v;

	v = 0;
	pthread_create(&newthread, NULL, myturn, &v);
	yourturn();
	pthread_join(newthread, NULL);
	printf("thread's done: v=%d\n", v);
}
