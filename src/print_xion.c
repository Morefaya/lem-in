/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 15:15:24 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/15 15:15:26 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_xion(t_list *xion)
{
	t_list	*tmp;
	char	*name;

	while (xion)
	{
		tmp = ((t_xion*)(xion->content))->pipe;
		name = ((t_hill*)(tmp->content))->n;
		ft_printf("xion: %s\taddr :%p\n", name, tmp);
		xion = xion->next;
	}
}
