/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:58:01 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/12 18:31:22 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"
#include <signal.h>

int	g_msg = 1;

static void send_str(char *str, int i, int bit_counter, int pid)
{
	while (str[i] != '\0')
	{
		while (bit_counter <= 7)
		{
			g_msg = 0;
			if ((str[i] >> bit_counter) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit_counter++;
		}
		while (g_msg == 0)
			;
		bit_counter = 0;
		i++;
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
	
	if (argc != 3)
		return (ft_printf("%s\n", "Error!\nMissing PID or String!"), 1);
	if (check_pid(argv[1]) != 0)
		return (ft_printf("%s\n", "Error!\nWrong PID!"), 1);
	siga.sa_flags = 0;
	siga.sa_handler = msg_return;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	pid_s = ft_atoi(argv[1]);
	send_str(argv[2], 0, 0, pid_s);
	return (0);
}
