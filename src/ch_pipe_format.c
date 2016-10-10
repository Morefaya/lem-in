/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_pipe_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:14:39 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/10 21:06:54 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_name(char *name, t_list *r_lst)
{
	char	*str;

	while (r_lst)
	{
		str = ((t_room*)(r_lst->content))->n;
		if (!ft_strcmp(name, str))
			return (0);
		r_lst = r_lst->next;
	}
	return (1);
}

static int	first_step(char *line, t_list *r_lst, int *i, int *j)
{
	char	*n_1;

	*i = 0;
	*j = 0;
	while (line[*i] && ft_strchr(" \t", line[*i]))
		(*i)++;
	while (line[*i + *j] && !ft_strchr(" \t-", line[*i + *j]))
		(*j)++;
	if (!(n_1 = ft_strsub(line, *i, *j)))
		return (10);
	if (check_name(n_1, r_lst))
	{
		free(n_1);
		return (11);
	}
	free(n_1);
	(*i) += *j;
	*j = 0;
	return (0);
}

static int	second_step(char *line, t_list *r_lst, int *i, int *j)
{
	char	*n_1;

	while (line[*i] && ft_strchr(" \t", line[*i]))
		(*i)++;
	if (!line[*i])
		return (3);
	while (line[*i + *j] && !ft_strchr(" \t-", line[*i + *j]))
		(*j)++;
	if (!(n_1 = ft_strsub(line, *i, *j)))
		return (10);
	if (check_name(n_1, r_lst))
	{
		free(n_1);
		return (11);
	}
	free(n_1);
	(*i) += *j;
	*j = 0;
	return (0);
}

int			ch_pipe_format(char *line, t_list *r_lst)
{
	int		i;
	int		j;
	int		ret;

	if (!ft_strchr(line, '-'))
		return (1);
	if ((ret = first_step(line, r_lst, &i, &j)))
		return (ret);
	while (line[i] && ft_strchr(" \t", line[i]))
		i++;
	if (line[i] == '-')
		i++;
	else
		return (2);
	if ((ret = second_step(line, r_lst, &i, &j)))
		return (ret);
	if (line[i] == '-')
		return (4);
	while (line[i])
	{
		if (!ft_strchr(" \t", line[i]))
			return (5);
		i++;
	}
	return (0);
}
