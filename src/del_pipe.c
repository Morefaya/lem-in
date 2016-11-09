/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:01:15 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/09 16:01:17 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_pipe(t_pipe *pipe, size_t ct)
{
	free(pipe->n_1);
	free(pipe->n_2);
	ft_bzero(pipe, ct);
	free(pipe);
}
