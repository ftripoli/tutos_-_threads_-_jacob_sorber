/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftripoli <ftripoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:29:56 by ftripoli          #+#    #+#             */
/*   Updated: 2025/06/16 19:30:29 by ftripoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/**
 * with no threads the code is suck in the myturn while loop and can't execute
 * the your turn print
 */
void	myturn(void)
{
	while (1)
	{
		sleep(1);
		printf("my Turn!\n");
	}
}

void	yourturn(void)
{
	while (1)
	{
		sleep(2);
		printf("Your Turn!\n");
	}
}

int	main(void)
{
	myturn();
	yourturn();
}
