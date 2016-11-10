/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_lstpipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:27:29 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/10 15:27:54 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	deal_com(t_list **line_lst, int *i)
{
	char	*str;

	str = ((t_line*)((*line_lst)->content))->line;
	while (*str == '#')
	{
		(*i)++;
		ft_lstrotate(line_lst);
		str = ((t_line*)((*line_lst)->content))->line;
	}
}

static void	deal_add(t_list **r_lst, t_list **tmp)
{
	if (!*r_lst)
		ft_lstadd(r_lst, *tmp);
	else if (!diff_pipe(*tmp, *r_lst))
		ft_lstadd_back(*r_lst, *tmp);
	else
		ft_lstdel(tmp, (void(*)(void*, size_t))del_pipe);
}

t_list		*mk_lstpipe(t_list **line_lst, t_list *r_lst)
{
	t_mk_lstr	data;

	data.i = 0;
	data.r_lst = NULL;
	data.str = ((t_line*)((*line_lst)->content))->line;
	data.len = ft_lstcount(*line_lst) - 1;
	while ((!ch_pipe_format(data.str, r_lst) && data.i < data.len)
		|| (*data.str == '#' && data.i < data.len))
	{
		deal_com(line_lst, &data.i);
		data.str = ((t_line*)((*line_lst)->content))->line;
		if (ch_pipe_format(data.str, r_lst))
			break ;
		if (!(data.tmp = get_pipe(data.str, r_lst)))
		{
			ft_lstdel(&data.r_lst, (void(*)(void*, size_t))del_pipe);
			return (NULL);
		}
		deal_add(&data.r_lst, &data.tmp);
		ft_lstrotate(line_lst);
		data.str = ((t_line*)((*line_lst)->content))->line;
		(data.i)++;
	}
	return (data.r_lst);
}
