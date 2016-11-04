/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:40:03 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/04 17:01:02 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_move(t_list *a_lst, t_list *h_lst)
{
	char	*str;
	int		nu_ant;

	nu_ant = ((t_ant*)((a_lst)->content))->nu;
	while (h_lst)
	{
		str = ((t_hill*)(h_lst->content))->n;
		if (((t_ant*)((a_lst)->content))->hill == h_lst)
		{
			ft_printf("L%d-%s ", nu_ant, str);
			return ;
		}
		h_lst = h_lst->next;
	}
}
