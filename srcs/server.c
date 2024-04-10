/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:57:42 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/09 21:07:53 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"
#include <signal.h>

static t_handler_bit	g_result;

static void	sig_handler(int signal_number)
{
	if (signal_number == SIGUSR1 || signal_number == SIGUSR2)
	{
		if (g_result.bit_counter == 8)
		{
			g_result.char_index++;
			g_result.bit_counter = 0;
		}
		g_result.str[g_result.char_index] |= (signal_number == SIGUSR2
			|| signal_number == SIGUSR1) << g_result.bit_counter;
		g_result.bit_counter++;
	}
}

int main(void)
{
	struct sigaction sa;
	
	g_result = (t_handler_bit){0};
	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("Error!\nSIGACTION FAILED"), 1);
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		if (g_result.str[g_result.char_index] == '\0')
		{
			ft_printf("Received INFOR: %s\n", g_result.str);
			ft_memset(g_result.str, 0, 1024);
			g_result.bit_counter = 0;
			g_result.char_index = 0;
		}
		pause ();
	}
    return (0);
}
