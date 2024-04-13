/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:58:01 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/13 18:28:12 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>

int	g_msg = 1;

static void send_str(char to_send, int bit_counter, int pid)
{
		while (bit_counter >= 0 && bit_counter <= 7)
		{
			g_msg = 0;
			if ((to_send >> bit_counter) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			while (g_msg == 0)
				;
			bit_counter++;
		}
}

static int	check_pid(char *pid_s)
{
	while (*pid_s++)
		if (ft_isdigit(*pid_s - '0') == 1)
			return (1);
	return (0);
}

static void	msg_return(int sig)
{
	if (sig == SIGUSR1)
		g_msg = 1;
	if (sig == SIGUSR2)
		ft_printf("Received!\n");
}

int main(int argc, char *argv[])
{
	int					pid_s;
	struct sigaction	siga;
	char				*to_send;
	
	if (argc != 3)
		return (ft_printf("%s\n", "Error!\nMissing PID or String!"), EXIT_FAILURE);
	if (check_pid(argv[1]) != 0)
		return (ft_printf("%s\n", "Error!\nWrong PID!"), EXIT_FAILURE);
	to_send = argv[2];
	siga.sa_flags = 0;
	siga.sa_handler = msg_return;
	if (sigaction(SIGUSR1, &siga, NULL) == -1
		|| sigaction(SIGUSR2, &siga, NULL) == -1)
		return (ft_printf("Error!\nSIGACTION FAILED"), EXIT_FAILURE);
	pid_s = ft_atoi(argv[1]);
	while (*to_send)
	{
		ft_printf("char: %c", *to_send);
		send_str(*to_send, 0, pid_s);
		to_send++;
	}
	return (EXIT_SUCCESS);
}
