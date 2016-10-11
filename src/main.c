/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 21:17:15 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/10 20:56:52 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_list	*line_lst;
	int		nb_ant;
	int		len_l;
	int		i;
	t_list	*r_lst;
	t_list	*p_lst;

	if (!(line_lst = get_anthill()))
		return (1);
	len_l = ft_lstcount(line_lst);
	if ((nb_ant = check_nbant(line_lst)) <= 0)
	{
		ft_lstdel(&line_lst, (void(*)(void*, size_t))del_line);
		ft_printf("Error\n");
		return (1);
	}
	ft_printf("nb_ant :%d\n", nb_ant);
	ft_lstrotate(&line_lst);
	i = 1;
	if (!(r_lst = mk_lstroom(&line_lst)))
	{
		ft_lstdel(&line_lst, (void(*)(void*, size_t))del_line);
		return (1);
	}
	print_r_lst(r_lst);
	if (!(p_lst = mk_lstpipe(&line_lst, r_lst)))
	{
		ft_lstdel(&line_lst, (void(*)(void*, size_t))del_line);
		ft_lstdel(&r_lst, (void(*)(void*, size_t))del_room);
		return (1);
	}
	print_p_lst(p_lst);
	ft_lstdel(&r_lst, (void(*)(void*, size_t))del_room);
	ft_lstdel(&p_lst, (void(*)(void*, size_t))del_pipe);
	ft_lstdel(&line_lst, (void(*)(void*, size_t))del_line);
	//while (42);
	return (0);
}
