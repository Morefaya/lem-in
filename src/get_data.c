/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:01:38 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/10 18:06:04 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		init_var(t_data *data)
{
	data->lst = NULL;
	data->fd = 0;
	data->i = 1;
	data->cond = 0;
}

static t_list	*print_error_1(t_list **lst)
{
	ft_printf("invalid option\n");
	ft_lstdel(lst, (void(*)(void*, size_t))del_line);
	return (NULL);
}

static t_list	*print_error_2(t_list **lst, int i, char **av)
{
	ft_printf("no such file: %s\n", av[i]);
	ft_lstdel(lst, (void(*)(void*, size_t))del_line);
	return (NULL);
}

t_list			*get_data(int ac, char **av, int *opt)
{
	t_data	d;

	init_var(&d);
	if (ac == 1)
		get_anthill(0, &d.lst);
	while (d.i < ac)
	{
		if (av[d.i][0] == '-' && !d.cond)
		{
			if (check_opt(av[d.i], opt))
				return (print_error_1(&d.lst));
		}
		else
		{
			d.cond = 1;
			if ((d.fd = open(av[d.i], O_RDONLY)) < 0)
				return (print_error_2(&d.lst, d.i, av));
			get_anthill(d.fd, &d.lst);
			close(d.fd);
		}
		d.i++;
	}
	if (d.i && !d.cond)
		get_anthill(0, &d.lst);
	return (d.lst);
}
