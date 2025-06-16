/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_download_google.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftripoli <ftripoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:34:59 by ftripoli          #+#    #+#             */
/*   Updated: 2025/06/16 20:06:18 by ftripoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/socket.h> /* basic socket definitions */
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdarg.h> /* for variadic function */
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <netdb.h>
#include <stdint.h>
#include <pthread.h>

// standard HTTP port
#define SERVER_PORT 80

#define MAXLINE 4096
#define SA struct sockaddr

#define BIG 1000000000UL

uint32_t		g_counter = 0;
pthread_mutex_t	g_lock = PTHREAD_MUTEX_INITIALIZER;

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

char	*get_home_page(char *ipaddr, int *bytesread)
{
	int					sockfd;
	int					n;
	int					sendbytes;
	struct sockaddr_in	servaddr;
	char				sendline[MAXLINE];
	char				*buffer;

	buffer = malloc(MAXLINE);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		return (NULL);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERVER_PORT);/* web server*/
	if (inet_pton(AF_INET, ipaddr, &servaddr.sin_addr) <= 0)
		return (NULL);
	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
		return (NULL);
	// We're connected. Prepare the message.
	sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
	sendbytes = strlen(sendline);
	//Send the request
	if (write(sockfd, sendline, sendbytes) != sendbytes)
		return (NULL);

	memset(buffer, 0, MAXLINE);

	//Now read the first MAXLINE server's response.
	n = read(sockfd, buffer, MAXLINE - 1);
	if (n < 0)
		return (NULL);
	*bytesread = n;
	return (buffer);
}

int	main(void)
{
	pthread_t	t;
	char		*buf;
	int			buflen;

	pthread_create(&t, NULL, count_to_big, NULL);
	// count_to_big(NULL);
	buf = get_home_page("172.217.0.78", &buflen);
	pthread_join(t, NULL);
	printf("Done. Counter = %u. Recved %d bytes\n", g_counter, buflen);
}
