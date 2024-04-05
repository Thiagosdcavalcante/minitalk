/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:57:42 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/05 17:29:09 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/minitalk.h"

int main(int argc, char *argv[])
{
	(void)argv;
    if (argc >= 2)
    {
		ft_printf("PID: %d", getpid());
        return (0);
    }
    return (0);
}
