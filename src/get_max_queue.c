/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:47:35 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/10 20:55:14 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	count_pipe(t_list *h_lst)
{
	t_list	*xion;
	int		ret;

	ret = 0;
	xion = ((t_hill*)(h_lst->content))->xion;
	while (xion)
	{
		ret++;
		xion = xion->next;
	}
	return (ret);
}

int			get_max_queue(t_list *h_lst)
{
	int	cmd;
	int	nb_pipe_1;
	int	nb_pipe_2;

	nb_pipe_1 = 0;
	nb_pipe_2 = 0;
	while (h_lst)
	{
		cmd = ((t_hill*)(h_lst->content))->cmd;
		if (cmd == START)
			nb_pipe_1 = count_pipe(h_lst);
		else if (cmd == END)
			nb_pipe_2 = count_pipe(h_lst);
		h_lst = h_lst->next;
	}
	if (nb_pipe_1 < nb_pipe_2)
		return (nb_pipe_1);
	else
		return (nb_pipe_2);
}
