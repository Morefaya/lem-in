/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:18:42 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/04 17:42:00 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_hill(t_list *hill)
{
	char	*str;
	int	cmd;
	t_list *tmp;
	int	ant;

	while (hill)
	{
		str = ((t_hill*)(hill->content))->n;
		cmd = ((t_hill*)(hill->content))->cmd;
		tmp = ((t_hill*)(hill->content))->a_lst;
		if (tmp)
			ant = ((t_ant*)(tmp->content))->nu;
		else
			ant = -1;
		ft_printf("hill :%s\taddr :%p\tcmd :%d\t ant_addr :%p\tant :%d\n", str, hill, cmd, tmp, ant);
		/*if (((t_hill*)(hill->content))->xion)
		{
			print_xion(((t_hill*)(hill->content))->xion);
			ft_printf("\n");
		}*/
		/*if (((t_hill*)(hill->content))->a_lst)
		{
			print_ant(((t_hill*)(hill->content))->a_lst);
			ft_printf("\n");
		}*/
		ft_printf("\n");
		hill = hill->next;
	}
}
