/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_estate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:08:29 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/09 15:56:04 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	refresh(t_list *h_lst, t_list *a_lst, t_list **tmp, int *cmd)
{
	char	*str;

	str = ((t_hill*)(h_lst->content))->n;
	ft_printf("%s : ", str);
	*tmp = a_lst;
	*cmd = ((t_hill*)(h_lst->content))->cmd;
}

void	print_estate(t_list *h_lst, t_list *a_lst)
{
	t_list	*tmp;
	int		nu;
	int		cmd;

	while (h_lst)
	{
		refresh(h_lst, a_lst, &tmp, &cmd);
		while (tmp)
		{
			if (((t_ant*)(tmp->content))->hill == h_lst)
			{
				nu = ((t_ant*)(tmp->content))->nu;
				ft_printf("L%d ", nu);
			}
			tmp = tmp->next;
		}
		if (cmd == START)
			ft_printf(" <- START");
		else if (cmd == END)
			ft_printf(" <- END");
		ft_printf("\n");
		h_lst = h_lst->next;
	}
}
