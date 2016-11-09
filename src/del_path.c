/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:00:35 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/09 16:00:47 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_path(t_xion *path, size_t size)
{
	ft_lstdel(&path->pipe, (void(*)(void*, size_t))del_xion);
	ft_bzero(path, size);
	free(path);
}
