/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_room_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:17:19 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/10 19:17:21 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	abscisse(char **line)
{
	while (**line && ft_strchr(" \t", **line))
		(*line)++;
	if (**line == '-')
	{
		if (ft_isdigit(*((*line) + 1)))
			(*line)++;
		else
			return (2);
	}
	while (**line && ft_isdigit(**line))
		(*line)++;
	if (!**line || !ft_strchr(" \t", **line))
		return (3);
	return (0);
}

static int	ordonne(char **line)
{
	while (**line && ft_strchr(" \t", **line))
		(*line)++;
	if (**line == '-')
	{
		if (ft_isdigit(*((*line) + 1)))
			(*line)++;
		else
			return (4);
	}
	while (**line && ft_isdigit(**line))
		(*line)++;
	if (**line && !ft_strchr(" \t", **line))
		return (5);
	while (**line)
	{
		if (!ft_strchr(" \t", **line))
			return (6);
		(*line)++;
	}
	return (0);
}

int		ch_room_format(char *line)
{
	int	ret;

	while (*line && ft_strchr(" \t", *line))
		line++;
	while (*line && !ft_strchr(" \t", *line) && ft_isprint(*line))
		line++;
	if (!*line || !ft_isprint(*line))
		return (1);
	if ((ret = abscisse(&line)))
		return (ret);
	else if ((ret = ordonne(&line)))
		return (ret);
	return (0);
}
