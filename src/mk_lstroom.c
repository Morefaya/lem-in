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
	if (*str == '#')
	{
		if (!ft_strcmp("##start", str))
			conf = START;
		else if (!ft_strcmp("##end", str))
			conf = END;
		(*i)++;
		ft_lstrotate(line_lst);
	}
	return (conf);
}

t_list		*mk_lstroom(t_list **line_lst)
{
	t_mk_lstr	data;

	data.i = 0;
	data.r_lst = NULL;
	data.str = ((t_line*)((*line_lst)->content))->line;
	while ((!ch_room_format(data.str) && data.i < (ft_lstcount(*line_lst) - 1))
		|| (*data.str == '#' && data.i < (ft_lstcount(*line_lst) - 1)))
	{
		data.conf = deal_com(line_lst, &data.i);
		data.str = ((t_line*)((*line_lst)->content))->line;
		if (!(data.tmp = get_room(data.str, data.conf)))
		{
			ft_lstdel(&data.r_lst, (void(*)(void*, size_t))del_room);
			return (NULL);
		}
		if (!data.r_lst)
			ft_lstadd(&data.r_lst, data.tmp);
		else if (!diff_room(data.tmp, data.r_lst))
			ft_lstadd_back(data.r_lst, data.tmp);
		else
			ft_lstdel(&data.tmp, (void(*)(void*, size_t))del_room);
		ft_lstrotate(line_lst);
		data.str = ((t_line*)((*line_lst)->content))->line;
		(data.i)++;
	}
	return (data.r_lst);
}
