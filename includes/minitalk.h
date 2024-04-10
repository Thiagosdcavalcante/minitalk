/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:54:36 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/09 20:26:34 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libs/libft/libft.h"
# include <signal.h>
# include <unistd.h>

typedef struct s_handler_bit
{
	char	str[1024];
	int	bit_counter;
	int	char_index;
} t_handler_bit;

#endif
