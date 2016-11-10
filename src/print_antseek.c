/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_antseek.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:30:54 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/10 15:30:56 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_antseek(t_list *s_lst)
{
	t_list	*p;
	int		i;

	i = 0;
	while (s_lst)
	{
		i++;
		p = ((t_xion*)(s_lst->content))->pipe;
		ft_printf("L %d :%p\n", i, p);
		s_lst = s_lst->next;
	}
}
