/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 15:12:28 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/15 16:39:37 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_path(t_list *path)
{
	while (path)
	{
		print_xion(((t_xion*)(path->content))->pipe);
		path = path->next;
		if (path)
			ft_printf("\n");
	}
}
