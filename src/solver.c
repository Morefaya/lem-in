/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:42:35 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/10 16:27:21 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		get_totlen(t_list *path)
{
	int		len;
	int		i;
	t_list	*tmp_1;
	t_list	*tmp_2;

	len = 0;
	tmp_1 = XION(path);
	while (tmp_1)
	{
		i = 0;
		tmp_2 = XION(tmp_1);
		while (tmp_2)
		{
			i++;
			tmp_2 = tmp_2->next;
		}
		len += i;
		tmp_1 = tmp_1->next;
	}
	return (len);
}

static t_list	*get_end(t_list *h_lst)
{
	while (h_lst)
	{
		if (((t_hill*)(h_lst->content))->cmd == END)
			return (h_lst);
		h_lst = h_lst->next;
	}
	return (NULL);
}

static int		check_loop(t_list *s_lst, t_list *end)
{
	while (s_lst)
	{
		if (((t_ant*)(s_lst->content))->hill != end)
			return (1);
		s_lst = s_lst->next;
	}
	return (0);
}

void			move_ant(t_list *a_lst, t_list *path, t_list *end, int opt)
{
	t_list		*tmp_1;
	t_list		*tmp_2;
	t_d_move	a;

	tmp_1 = path;
	tmp_2 = a_lst;
	while (a_lst)
	{
		a.ant = a_lst;
		a.a_lst = tmp_2;
		a.path = path;
		a.end = end;
		a.opt = opt;
		deal_move(a);
		path = path->next;
		path = (path) ? path : tmp_1;
		a_lst = a_lst->next;
	}
	if (opt & PRINT)
		ft_putchar('\n');
}

int				solver(t_list **a_lst, t_list **h_lst, t_list **path, int opt)
{
	t_solver	s;

	s.nb_ant = ft_lstcount(*a_lst);
	s.end = get_end(*h_lst);
	s.j = 0;
	s.i = get_totlen(*path) + s.nb_ant;
	if ((opt & PRINT) && (opt & OPT_A))
	{
		print_estate(*h_lst, *a_lst);
		ft_putchar('\n');
	}
	while (check_loop(*a_lst, s.end) && s.j < s.i)
	{
		move_ant(*a_lst, *path, s.end, opt);
		s.j++;
		if ((opt & PRINT) && (opt & OPT_A))
		{
			print_estate(*h_lst, *a_lst);
			if (check_loop(*a_lst, s.end))
				ft_putchar('\n');
		}
	}
	if ((opt & PRINT) && (opt & OPT_B))
		ft_printf("Nombre de tour: %d\n", s.j);
	return (s.j);
}
