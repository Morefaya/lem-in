/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_anthill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:29:37 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/09 19:43:33 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_line(char *line)
{
	int		i;

	if (!ft_strcmp(line, ""))
		return (1);
	i = 0;
	while (line[i] && ft_strchr(" \t", line[i]))
		i++;
	if (!line[i])
		return (2);
	else
		return (0);
}

t_list		*get_anthill(void)
{
	char	*line;
	t_list	*lst;
	t_list	*tmp;
	t_line	content;

	lst = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!check_line(line))
		{
			content.line = line;
			if (!(tmp = ft_lstnew(&content, sizeof(content))))
				return (NULL);
			if (!lst)
				ft_lstadd(&lst, tmp);
			else
				ft_lstadd_back(lst, tmp);
		}
		else
			free(line);
	}
	free(line);
	return (lst);
}
