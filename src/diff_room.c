/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:05:51 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/10 15:05:53 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	diff_room(t_list *r_new, t_list *r_lst)
{
	char	*str_1;
	char	*str_2;

	while (r_lst)
	{
		str_1 = ((t_room*)(r_new->content))->n;
		str_2 = ((t_room*)(r_lst->content))->n;
		if (!ft_strcmp(str_1, str_2))
			return (1);
		r_lst = r_lst->next;
	}
	return (0);
}
