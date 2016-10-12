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

	while (hill)
	{
		str = ((t_hill*)(hill->content))->n;
		ft_printf("hill :%s\n", str);
		print_xion(((t_hill*)(hill->content))->xion);
		hill = hill->next;
	}
}
