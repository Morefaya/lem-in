/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_antlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:47:44 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/12 18:16:20 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*get_antlst(int nb_ant, t_list *h_lst)
{
	int		i;
	t_ant	content;
	t_list	*a_lst;
	t_list	*tmp;

	i = 1;
	a_lst = NULL;
	while (i <= nb_ant)
	{
		content.nu = i;
		content.hill = h_lst;
		if (!(tmp = ft_lstnew(&content, sizeof(content))))
		{
			ft_lstdel(&a_lst, (void(*)(void*, size_t))del_ant);
			return (NULL);
		}
		if (!a_lst)
			ft_lstadd(&a_lst, tmp);
		else
			ft_lstadd_back(a_lst, tmp);
		i++;
	}
	return (a_lst);
}
