/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:18:42 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/12 17:25:34 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_hill(t_list *hill)
{
	char	*str;
	int	cmd;

	while (hill)
	{
		str = ((t_hill*)(hill->content))->n;
		cmd = ((t_hill*)(hill->content))->cmd;
		ft_printf("hill :%s\taddr :%p\tcmd :%d\n", str, hill, cmd);
		if (((t_hill*)(hill->content))->xion)
		{
			print_xion(((t_hill*)(hill->content))->xion);
			ft_printf("\n");
		}
		/*if (((t_hill*)(hill->content))->a_lst)
		{
			print_ant(((t_hill*)(hill->content))->a_lst);
			ft_printf("\n");
		}*/
		ft_printf("\n");
		hill = hill->next;
	}
}
