/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:23:34 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/10 16:24:57 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		check_ant_pos(t_list *a_lst, t_list *go_in)
{
	t_list	*tmp;

	while (a_lst)
	{
		tmp = ((t_ant*)(a_lst->content))->hill;
		if (tmp == go_in)
			return (1);
		a_lst = a_lst->next;
	}
	return (0);
}

int				deal_move(t_d_move a)
{
	t_list	*tmp;
	t_list	*way;
	char	*str;
	int		nu;

	nu = ((t_ant*)(a.ant->content))->nu;
	tmp = ((t_xion*)(a.path->content))->pipe;
	way = ((t_xion*)(tmp->content))->pipe;
	while (way != ((t_ant*)(a.ant->content))->hill)
	{
		tmp = tmp->next;
		way = ((t_xion*)(tmp->content))->pipe;
	}
	tmp = tmp->next;
	if (tmp)
		way = ((t_xion*)(tmp->content))->pipe;
	if ((check_ant_pos(a.a_lst, way) && way != a.end)
		|| ((t_ant*)(a.ant->content))->hill == a.end)
		return (1);
	str = ((t_hill*)(way->content))->n;
	((t_ant*)(a.ant->content))->hill = way;
	if (a.opt & PRINT)
		ft_printf("L%d-%s ", nu, str);
	return (0);
}
