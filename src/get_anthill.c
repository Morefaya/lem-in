/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_anthill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:29:37 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/09 18:07:39 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*get_anthill(void)
{
	char	*line;
	t_list	*lst;
	t_list	*tmp;
	t_line	content;

	lst = NULL;
	while (get_next_line(0, &line) > 0)
	{
		content.line = line;
		if (!(tmp = ft_lstnew(&content, sizeof(content))))
			return (NULL);
		if (!lst)
			ft_lstadd(&lst, tmp);
		else
			ft_lstadd_back(lst, tmp);
	}
	free(line);
	return (lst);
}
