/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 21:17:15 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/15 17:11:45 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_list	*line_lst;
	int	nb_ant;
	int	len_l;
	int	i;
	t_list	*r_lst;
	t_list	*p_lst;
	t_list	*h_lst;
	t_list	*a_lst;
	t_list	*w_lst;
	t_list	*ph_lst;
	t_list	*as_lst;

	if (!(line_lst = get_anthill()))
		return (1);
	len_l = ft_lstcount(line_lst);
	if ((nb_ant = check_nbant(line_lst)) <= 0)
	{
		ft_lstdel(&line_lst, (void(*)(void*, size_t))del_line);
		ft_printf("Error\n");
		return (1);
	}
	//ft_printf("nb_ant :%d\n", nb_ant);
	ft_lstrotate(&line_lst);
	i = 1;
	if (!(r_lst = mk_lstroom(&line_lst)))
	{
		ft_lstdel(&line_lst, (void(*)(void*, size_t))del_line);
		return (1);
	}
	//print_r_lst(r_lst);
	if (!(p_lst = mk_lstpipe(&line_lst, r_lst)))
	{
		ft_lstdel(&line_lst, (void(*)(void*, size_t))del_line);
		ft_lstdel(&r_lst, (void(*)(void*, size_t))del_room);
		return (1);
	}
	//print_p_lst(p_lst);
	h_lst = mk_anthill(&r_lst);
	a_lst = get_antlst(nb_ant, h_lst);
	//print_ant(a_lst);
	init_ant(a_lst, h_lst);
	init_xion(&h_lst, p_lst);
	//print_hill(h_lst);
	w_lst = NULL;
	ph_lst = NULL;
	as_lst = NULL;
	path_finder(h_lst, &w_lst, &ph_lst, &as_lst);
	//print_xion(w_lst);
	print_path(ph_lst);
	ft_lstdel(&w_lst, (void(*)(void*, size_t))del_xion);
	ft_lstdel(&r_lst, (void(*)(void*, size_t))del_room);
	ft_lstdel(&p_lst, (void(*)(void*, size_t))del_pipe);
	ft_lstdel(&line_lst, (void(*)(void*, size_t))del_line);
	ft_lstdel(&h_lst, (void(*)(void*, size_t))del_hill);
	ft_lstdel(&a_lst, (void(*)(void*, size_t))del_ant);
	//while (42);
	return (0);
}
