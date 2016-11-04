/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_estate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:08:29 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/04 17:26:31 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_estate(t_list *h_lst, t_list *a_lst)
{
	t_list	*tmp;
	int		nu;
	char	*str;

	while (h_lst)
	{
		str = ((t_hill*)(h_lst->content))->n;
		ft_printf("%s : ", str);
		tmp = a_lst;
		while (tmp)
		{
			if (((t_ant*)(tmp->content))->hill == h_lst)
			{
				nu = ((t_ant*)(tmp->content))->nu;
				ft_printf("L%d ", nu);
			}
			tmp = tmp->next;
		}
		ft_printf("\n");
		h_lst = h_lst->next;
	}
}
