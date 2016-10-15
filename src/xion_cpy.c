/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xion_cpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 16:22:36 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/15 16:36:47 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*xion_cpy(t_list *xion)
{
	t_list	*tmp;
	t_list	*cpy;
	t_xion	content;

	cpy = NULL;
	while (xion)
	{
		content.pipe = ((t_xion*)(xion->content))->pipe;
		if (!(tmp = ft_lstnew(&content, sizeof(content))))
		{
			ft_lstdel(&cpy, (void(*)(void*, size_t))del_xion);
			return (NULL);
		}
		if (!cpy)
			ft_lstadd(&cpy, tmp);
		else
			ft_lstadd_back(cpy, tmp);
		xion = xion->next;
	}
	return (cpy);
}
