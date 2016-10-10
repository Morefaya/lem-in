/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_r_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 17:05:59 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/10 18:05:27 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_r_lst(t_list *r_lst)
{
	char	*str;
	int		cmd;
	int		x;
	int		y;

	while (r_lst)
	{
		str = ((t_room*)(r_lst->content))->n;
		cmd = ((t_room*)(r_lst->content))->cmd;
		x = ((t_room*)(r_lst->content))->x;
		y = ((t_room*)(r_lst->content))->y;
		ft_printf("room: %s\tcmd: %d\tabs: %d\t ord: %d\n", str, cmd, x, y);
		r_lst = r_lst->next;
	}
}
