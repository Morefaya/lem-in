/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_lstroom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:39:16 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/10 19:57:46 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	deal_com(t_list **line_lst, int *i)
{
	char	*str;
	int		conf;

	conf = NONE;
	str = ((t_line*)((*line_lst)->content))->line;
	while (*str == '#')
	{
		if (!ft_strcmp("##start", str))
			conf = START;
		else if (!ft_strcmp("##end", str))
			conf = END;
		(*i)++;
		ft_lstrotate(line_lst);
		str = ((t_line*)((*line_lst)->content))->line;
	}
	return (conf);
}

static void	deal_add(t_list **r_lst, t_list **tmp)
{
	if (!*r_lst)
		ft_lstadd(r_lst, *tmp);
	else if (!diff_room(*tmp, *r_lst))
		ft_lstadd_back(*r_lst, *tmp);
	else
		ft_lstdel(tmp, (void(*)(void*, size_t))del_room);
}

t_list		*mk_lstroom(t_list **line_lst)
{
	t_mk_lstr	data;

	data.i = 0;
	data.r_lst = NULL;
	data.str = ((t_line*)((*line_lst)->content))->line;
	data.len = ft_lstcount(*line_lst) - 1;
	while ((!ch_room_format(data.str) && data.i < data.len)
		|| (*data.str == '#' && data.i < data.len))
	{
		data.conf = deal_com(line_lst, &data.i);
		data.str = ((t_line*)((*line_lst)->content))->line;
		if (ch_room_format(data.str))
			break ;
		if (!(data.tmp = get_room(data.str, data.conf)))
		{
			ft_lstdel(&data.r_lst, (void(*)(void*, size_t))del_room);
			return (NULL);
		}
		deal_add(&data.r_lst, &data.tmp);
		ft_lstrotate(line_lst);
		data.str = ((t_line*)((*line_lst)->content))->line;
		(data.i)++;
	}
	return (data.r_lst);
}
