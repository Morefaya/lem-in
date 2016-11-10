/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_anthill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:10:43 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/10 15:26:05 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ch_start_end(t_list *r_lst)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (r_lst)
	{
		if (((t_room*)(r_lst->content))->cmd == START)
			start = START;
		else if (((t_room*)(r_lst->content))->cmd == END)
			end = END;
		r_lst = r_lst->next;
	}
	if (start && end)
		return (0);
	else
		return (start | end);
}

static void		turn_to_start(t_list **r_lst)
{
	while (((t_room*)((*r_lst)->content))->cmd != START)
		ft_lstrotate(r_lst);
}

static t_list	*get_hill(t_list *r_lst)
{
	t_list	*h_link;
	t_list	*tmp;
	t_hill	content;

	h_link = NULL;
	while (r_lst)
	{
		content.n = ((t_room*)(r_lst->content))->n;
		content.a_lst = NULL;
		content.xion = NULL;
		content.cmd = ((t_room*)(r_lst->content))->cmd;
		if (!(tmp = ft_lstnew(&content, sizeof(content))))
		{
			ft_lstdel(&h_link, (void(*)(void*, size_t))del_hill);
			return (NULL);
		}
		if (!h_link)
			ft_lstadd(&h_link, tmp);
		else
			ft_lstadd_back(h_link, tmp);
		r_lst = r_lst->next;
	}
	return (h_link);
}

t_list			*mk_anthill(t_list **r_lst)
{
	t_list	*ant_h;

	if (ch_start_end(*r_lst))
		return (NULL);
	turn_to_start(r_lst);
	if (!(ant_h = get_hill(*r_lst)))
		return (NULL);
	return (ant_h);
}
