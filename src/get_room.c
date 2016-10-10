/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 20:00:17 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/09 20:54:21 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	bzero_room(t_room *room)
{
	room->n = NULL;
	room->cmd = 0;
	room->x = 0;
	room->y = 0;
}

static int	get_name(char *line, t_room *room)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] && ft_strchr(" \t", line[i]))
		i++;
	while (line[i + j] && !ft_strchr(" \t", line[i + j]))
		j++;
	room->n = ft_strsub(line, i, j);
	//ft_printf("get_name :%s\n", room->n);
	return (i + j);
}

static int	get_coord(char *line, t_room *room, int index)	
{
	int	i;
	int	j;

	//ft_printf("get_coor :%s\n", line + index);
	if (ft_maxint(line + index))
	{
		free(room->n);
		bzero_room(room);
		return (1);
	}
	room->x = ft_atoi(line + index);
	i = index;
	j = 0;
	while (line[i] && ft_strchr(" \t", line[i]))
		i++;
	while (line[i + j] && !ft_strchr(" \t", line[i + j]))
		j++;
	if (ft_maxint(line + i + j))
	{
		free(room->n);
		bzero_room(room);
		return (2);
	}
	room->y = ft_atoi(line + i + j);
	return (0);
}


t_list		*get_room(char *line, int cmd)
{
	t_list	*r_link;
	t_room	content;
	int	index;

	bzero_room(&content);
	r_link = NULL;
	index = get_name(line, &content);
	if (get_coord(line, &content, index))
		return (NULL);
	if (cmd == 1)
		content.cmd = START;
	else if (cmd == 2)
		content.cmd = END;
	else
		content.cmd = NONE;
	if (!(r_link = ft_lstnew(&content, sizeof(content))))
	{
		free(content.n);
		bzero_room(&content);
		return (NULL);
	}
	//ft_printf("GT_NAME :%s\nx :%d\ny :%d\n", content.n, content.x, content.y);
	//ft_printf("GT_NA_2 :%s\nx :%d\ny :%d\n", ((t_room*)(r_link->content))->n, ((t_room*)(r_link->content))->x, ((t_room*)(r_link->content))->y);
	return (r_link);
}
