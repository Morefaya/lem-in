/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:20:20 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/10 15:20:21 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_all(t_main *data)
{
	ft_lstdel(&data->cb_lst, (void(*)(void*, size_t))del_path);
	ft_lstdel(&data->ph_lst, (void(*)(void*, size_t))del_path);
	ft_lstdel(&data->s_lst, (void(*)(void*, size_t))del_xion);
	ft_lstdel(&data->w_lst, (void(*)(void*, size_t))del_xion);
	ft_lstdel(&data->r_lst, (void(*)(void*, size_t))del_room);
	ft_lstdel(&data->p_lst, (void(*)(void*, size_t))del_pipe);
	ft_lstdel(&data->line_lst, (void(*)(void*, size_t))del_line);
	ft_lstdel(&data->h_lst, (void(*)(void*, size_t))del_hill);
	ft_lstdel(&data->a_lst, (void(*)(void*, size_t))del_ant);
}
