/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_addr_hill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:06:07 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/13 20:06:11 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*get_addr_hill(char *n, t_list *h_lst)
{
	char	*name;

	while (h_lst)
	{
		name = ((t_hill*)(h_lst->content))->n;
		if (!ft_strcmp(n, name))
			return (h_lst);
		h_lst = h_lst->next;
	}
	return (NULL);
}
