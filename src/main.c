/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 21:17:15 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/10 20:56:59 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

static int	help_free(t_main *main, int ret)
{
	free_all(main);
	ft_printf("ERROR");
	return (ret);
}

static void	help_main(t_main *m)
{
	m->h_lst = mk_anthill(&m->r_lst);
	m->a_lst = get_antlst(m->nb_ant, m->h_lst);
	m->s_lst = mk_antseek_lst(m->a_lst);
	init_xion(&m->h_lst, m->p_lst);
	m->max_queue = get_max_queue(m->h_lst);
	path_finder(m->h_lst, &m->w_lst, &m->ph_lst);
}

int			main(int ac, char **av)
{
	t_main	m;

	init_main(&m);
	if (!(m.line_lst = get_data(ac, av, &m.opt)))
		return (1);
	m.len_l = ft_lstcount(m.line_lst);
	if ((m.nb_ant = check_nbant(m.line_lst)) <= 0)
		return (help_free(&m, 1));
	ft_lstrotate(&m.line_lst);
	if (!(m.r_lst = mk_lstroom(&m.line_lst)) || check_start_end(m.r_lst))
		return (help_free(&m, 2));
	if (!(m.p_lst = mk_lstpipe(&m.line_lst, m.r_lst)))
		return (help_free(&m, 3));
	help_main(&m);
	if (!m.ph_lst)
		return (help_free(&m, 4));
	m.cb_lst = brute_fcomb(&m.h_lst, &m.ph_lst, m.nb_ant, m.max_queue);
	print_line(m.line_lst);
	ft_putchar('\n');
	solver(&m.a_lst, &m.h_lst, &m.cb_lst, m.opt | PRINT);
	free_all(&m);
	return (0);
}
