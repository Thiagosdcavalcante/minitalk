/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:57:42 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/08 21:49:15 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

static void	sig_handler(int signal_number)
{
	if (signal_number == SIGUSR1)
		ft_printf("Signal Received! SIGUSR1\n");
	if (signal_number == SIGUSR2)
		ft_printf("Signal Received! SIGUSR2\n");
}

int main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
	{
		pause();
	}
    return (0);
}
