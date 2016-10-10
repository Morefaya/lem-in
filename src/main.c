/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 21:17:15 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/09 19:45:59 by jcazako          ###   ########.fr       */
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
	int		len_l;
	int		i;
	t_list		*lst_r;

	if (!(line_lst = get_anthill()))
		return (1);
	len_l = ft_lstcount(line_lst);
	if ((nb_ant = check_nbant(line_lst)) <= 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_printf("nb_ant :%d\n", nb_ant);
	ft_lstrotate(&line_lst);
	i = 1;
	lst_r = get_room(((t_line*)(line_lst->content))->line, NONE);
	char	*str = ((t_room*)(lst_r->content))->n;
	int	x = ((t_room*)(lst_r->content))->x;
	int	y = ((t_room*)(lst_r->content))->y;
	ft_printf("room: %s\nx: %d\ny: %d\n", str, x, y);
	/*while (i < len_l)
	{
		ft_printf("%s\n", ((t_line*)(line_lst->content))->line);
		ft_lstrotate(&line_lst);
		i++;
	}*/
	ft_lstdel(&line_lst, (void(*)(void*, size_t))del_content);
	return (0);
}
