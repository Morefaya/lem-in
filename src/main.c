/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 21:17:15 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/09 18:26:35 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	del_content(t_line *content, size_t size)
{
	free(content->line);
	ft_bzero(content, size);
	free(content);
}

int	main(void)
{
	t_list	*line_lst;
	int		nb_ant;

	if (!(line_lst = get_anthill()))
		return (1);
	nb_ant = check_nbant(line_lst);
	ft_printf("nb_ant :%d\n", nb_ant);
	print_line(line_lst);
	ft_lstdel(&line_lst, (void(*)(void*, size_t))del_content);
	return (0);
}
