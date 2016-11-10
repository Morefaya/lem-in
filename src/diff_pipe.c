/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:06:04 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/10 15:06:06 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	diff_pipe(t_list *p_new, t_list *p_lst)
{
	char	*new_1;
	char	*new_2;
	char	*pipe_1;
	char	*pipe_2;

	while (p_lst)
	{
		new_1 = ((t_pipe*)(p_new->content))->n_1;
		new_2 = ((t_pipe*)(p_new->content))->n_2;
		pipe_1 = ((t_pipe*)(p_lst->content))->n_1;
		pipe_2 = ((t_pipe*)(p_lst->content))->n_2;
		if ((!ft_strcmp(new_1, pipe_1) && !ft_strcmp(new_2, pipe_2))
			|| (!ft_strcmp(new_1, pipe_2) && !ft_strcmp(new_2, pipe_1)))
			return (1);
		p_lst = p_lst->next;
	}
	return (0);
}
