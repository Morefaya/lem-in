/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:39:00 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/09 15:41:52 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_way(t_list *pipe, t_list *w_lst)
{
	t_list	*addr;

	while (w_lst)
	{
		addr = ((t_xion*)(w_lst->content))->pipe;
		if (addr == pipe)
			return (1);
		w_lst = w_lst->next;
	}
	return (0);
}

static void	add_way(t_list *h_lst, t_list **w_lst)
{
	t_list	*tmp;
	t_xion	content;

	content.pipe = h_lst;
	if (!(tmp = ft_lstnew(&content, sizeof(content))))
		return ;
	if (!*w_lst)
		ft_lstadd(w_lst, tmp);
	else
		ft_lstadd_back(*w_lst, tmp);
}

static void	add_path(t_list **w_lst, t_list **ph_lst)
{
	t_list	*tmp;
	t_xion	content;

	content.pipe = xion_cpy(*w_lst);
	if (!(tmp = ft_lstnew(&content, sizeof(content))))
		return ;
	if (!*ph_lst)
		ft_lstadd(ph_lst, tmp);
	else
		ft_lstadd_back(*ph_lst, tmp);
}

void		path_finder(t_list *h_lst, t_list **w_lst, t_list **ph_lst)
{
	t_list	*xion;
	t_list	*pipe;
	t_list	*done;
	int		cmd;
	int		len_w;

	xion = ((t_hill*)(h_lst->content))->xion;
	done = NULL;
	cmd = ((t_hill*)(h_lst->content))->cmd;
	add_way(h_lst, w_lst);
	if (cmd == END)
		add_path(w_lst, ph_lst);
	while (xion)
	{
		pipe = ((t_xion*)(xion->content))->pipe;
		if (!check_way(pipe, done) && !check_way(pipe, *w_lst))
		{
			add_way(pipe, &done);
			path_finder(pipe, w_lst, ph_lst);
		}
		xion = xion->next;
	}
	ft_lstdel(&done, (void(*)(void*, size_t))del_xion);
	len_w = ft_lstcount(*w_lst);
	ft_lstdel_range(w_lst, len_w, (void(*)(void*, size_t))del_xion);
}
