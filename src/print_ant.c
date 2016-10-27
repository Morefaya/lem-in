/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 18:09:17 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/12 18:17:59 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_ant(t_list *a_lst)
{
	int		nu;
	t_list	*tmp;
	char	*str;

	while (a_lst)
	{
		nu = ((t_ant*)(a_lst->content))->nu;
		tmp = ((t_ant*)(a_lst->content))->hill;
		str = ((t_hill*)(tmp->content))->n;
		ft_printf("ant :%d\t addr :%p\troom :%s\n", nu, tmp, str);
		a_lst = a_lst->next;
	}
}
