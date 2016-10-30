/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 21:17:15 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/27 17:10:13 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	count_pipe(t_list *h_lst)
{
	t_list	*xion;
	int	ret;

	ret = 0;
	xion = ((t_hill*)(h_lst->content))->xion;
	while (xion)
	{
		ret++;
		xion = xion->next;
	}
	return (ret);
}

static int	get_max_queue(t_list *h_lst)
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

static int	check_start_end(t_list *r_lst)
{
	int	start;
	int	end;
	int	cmd;

	start = 0;
	end = 0;
	while (r_lst)
	{
		cmd = ((t_room*)(r_lst->content))->cmd;
		if (cmd == START)
			start = 1;
		else if (cmd == END)
			end = 1;
		r_lst = r_lst->next;
	}
	if (start && end)
		return (0);
	else
		return (1);
}

int		main(void)
{
	t_list	*line_lst;
	int		ret;
	int	nb_ant;
	int	len_l;
	int	i;
	t_list	*r_lst;
	t_list	*p_lst;
	t_list	*h_lst;
	t_list	*a_lst;
	t_list	*w_lst;
	t_list	*ph_lst;
	t_list	*s_lst;
	int	max_queue;

	if (!(line_lst = get_anthill()))
		return (1);
	len_l = ft_lstcount(line_lst);
	if ((nb_ant = check_nbant(line_lst)) <= 0)
	{
		ft_lstdel(&line_lst, (void(*)(void*, size_t))del_line);
		ft_printf("Error_1\n");
		return (1);
	}
	ft_lstrotate(&line_lst);
	i = 1;
	if (!(r_lst = mk_lstroom(&line_lst)) || check_start_end(r_lst))
	{
		ft_lstdel(&line_lst, (void(*)(void*, size_t))del_line);
		ft_printf("Error_2\n");
		return (1);
	}
	if (!(p_lst = mk_lstpipe(&line_lst, r_lst)))
	{
		ft_lstdel(&line_lst, (void(*)(void*, size_t))del_line);
		ft_lstdel(&r_lst, (void(*)(void*, size_t))del_room);
		ft_printf("Error_3\n");
		return (1);
	}
	h_lst = mk_anthill(&r_lst);
	a_lst = get_antlst(nb_ant, h_lst);
	s_lst = NULL;
	s_lst = mk_antseek_lst(a_lst);
	init_xion(&h_lst, p_lst);
	max_queue = get_max_queue(h_lst);
	w_lst = NULL;
	ph_lst = NULL;
	path_finder(h_lst, &w_lst, &ph_lst);
	//print_path(ph_lst);
	//ft_printf("\n\ncomb:\n\n\n");
	ret = solver(&a_lst, &h_lst, &ph_lst);
	t_list	*comb;
	comb = NULL;
	//comb = get_comb(ph_lst, 2);
	//ft_printf("%p\n", comb);
	/*while (comb)
	{
		ft_printf("PAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAATH\n");
		print_path(((t_xion*)(comb->content))->pipe);
		comb = comb->next;
	}*/
	ft_lstdel(&comb, (void(*)(void*, size_t))del_xion);
	ft_lstdel(&s_lst, (void(*)(void*, size_t))del_xion);
	ft_lstdel(&w_lst, (void(*)(void*, size_t))del_xion);
	ft_lstdel(&r_lst, (void(*)(void*, size_t))del_room);
	ft_lstdel(&p_lst, (void(*)(void*, size_t))del_pipe);
	ft_lstdel(&line_lst, (void(*)(void*, size_t))del_line);
	ft_lstdel(&h_lst, (void(*)(void*, size_t))del_hill);
	ft_lstdel(&a_lst, (void(*)(void*, size_t))del_ant);
	while (42);
	return (0);
}
