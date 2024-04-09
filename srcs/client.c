/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:58:01 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/09 17:46:59 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

static void send_str(char *str, int i, int bit_counter, int pid)
{
	if (str[i] != '\0')
	{
		ft_printf("%c\n", str[i]);
		if (bit_counter > 7)
			bit_counter = 0;
		if ((str[i] >> bit_counter) & 1)
		{
			ft_printf("%s", "Signal sent: SIGURS2\n");
			kill(pid, SIGUSR2);
		}
		else
		{
			ft_printf("%s", "Signal sent: SIGURS1\n");
			kill(pid, SIGUSR1);
		}
		send_str(str, i + 1, bit_counter + 1, pid);
	}
		
}

static int	check_pid(char *pid_s)
{
	while (*pid_s++)
		if (ft_isdigit(*pid_s - '0') == 1)
			return (1);
	return (0);
}

int main(int argc, char *argv[])
{
	int	pid_s;

	if (argc == 3)
	{
		if (check_pid(argv[1]) == 0)
		{
			pid_s = ft_atoi(argv[1]);
			send_str(argv[2], 0, 0, pid_s);
		}
		else
			return (ft_printf("%s\n", "Error!\nWrong PID!"), 1);
	}
	else
		return (ft_printf("%s\n", "Error!\nMissing PID or String!"), 1);
	return (0);
}
