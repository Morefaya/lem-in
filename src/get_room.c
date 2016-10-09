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

static void	get_name(char *line, t_room *room)
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
	i += j;
	j = 0;
	if (strlen_space(line + i) > 0)
	{
		free(room->n);
		bzero_room(room);
		return ;
	}
	room->
	while (line[i] && ft_strchr(" \t", line[i]))
		i++;
	while (line[i + j] && !ft_strchr(" \t", line[i + j]))
		j++;
}

static int	

t_list		*get_room(char *line)
{
	t_list	*room;
	t_list	*tmp;
	t_room	content;

	bzero_room(&content);
	room = NULL;
	

}
