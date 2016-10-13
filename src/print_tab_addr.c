/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:29:56 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/13 20:42:56 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_tab_addr(t_list **tab)
{
	t_list	*tmp;

	tmp = *tab;
	while (tmp)
	{
		ft_printf("addr :%p\n", tmp);
		tmp = tmp->next;
	}
}
