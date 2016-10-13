/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 19:23:34 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/13 19:30:25 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	get_xion(t_list *h_lst, t_list *p_lst)
{
	
}

void		mk_pipe(t_list *h_lst, t_list *p_lst)
{
	int		i;

	i = 0;
	while (h_lst)
	{
		get_xion(h_lst, p_lst);
		h_lst = h_lst->next;
	}
}
