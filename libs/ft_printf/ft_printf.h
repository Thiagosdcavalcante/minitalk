/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:17:14 by tsantana          #+#    #+#             */
/*   Updated: 2024/04/05 17:20:37 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_pf_list
{
	char			character;
	struct s_pf_list	*next;
}	t_pf_list;

t_pf_list	*pf_ft_lstnew(char content);
void	pf_ft_lstadd_back(t_pf_list **lst, t_pf_list *pf_new);
void	pf_ft_putnumb(unsigned long n, t_pf_list **list);
void	pf_ft_put_address(unsigned long int address, t_pf_list **list);
void	pf_str_to_list(char *src, t_pf_list **list);
void	pf_putnbr_convert(unsigned long int n, t_pf_list **list, char *hexas);
int		ft_printf(const char *str, ...);

#endif
