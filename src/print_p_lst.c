/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:49:20 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/09 15:49:23 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_p_lst(t_list *p_lst)
{
	char	*n_1;
	char	*n_2;

	while (p_lst)
	{
		n_1 = ((t_pipe*)(p_lst->content))->n_1;
		n_2 = ((t_pipe*)(p_lst->content))->n_2;
		ft_printf("n_1: %s\t n_2: %s\n", n_1, n_2);
		p_lst = p_lst->next;
	}
}
