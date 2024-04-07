/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:58:01 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/07 20:21:54 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"
#include "minitalk.h"

// static int	check_pid(char *pid_s, int index)
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
			ft_printf("PID: %d\nSTRING: %s\n", pid_s, argv[2]);
		}
		else
			return (ft_printf("%s\n", "Error!\nWrong PID!"), 1);
	}
	else
		return (ft_printf("%s\n", "Error!\nMissing PID or String!"), 1);
	return (0);
}
