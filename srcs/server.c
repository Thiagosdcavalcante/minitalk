/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:57:42 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/13 18:31:44 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <bits/types/siginfo_t.h>

static void	sig_handler(int signal_number, siginfo_t *infor, void *ucontext)
{
	static char	byte_print;
	static int			bit_counter;
	
	if (!ucontext)
		return ;
	if (signal_number == SIGUSR1 || signal_number == SIGUSR2)
	{
		byte_print |= (signal_number == SIGUSR2)
			<< bit_counter;
		bit_counter++;
	}
	if (bit_counter == 8)
	{
		write(1, &byte_print, 1);
		bit_counter = 0;
		byte_print = 0;
	}
	kill(infor->si_pid, SIGUSR1);
}

int main(void)
{
	struct sigaction sa;
	
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("Error!\nSIGACTION FAILED"), EXIT_FAILURE);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause ();
    return (EXIT_SUCCESS);
}
