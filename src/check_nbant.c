/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nbant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 18:10:13 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/09 18:40:34 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	strlen_space(char *str)
{
	int		i;

	i = 0;
	while (*str && ft_strchr(" \t", *str))
		str++;
	while (str[i] && ft_strchr("0123456789", str[i]))
		i++;
	return (i);
}

int			check_nbant(t_list *lst)
{
	int		i;
	char	*str;
	int		nb_ant;

	i = 0;
	str = ((t_line*)(lst->content))->line;
	while (str[i] && ft_strchr(" \t", str[i]))
		i++;
	while (str[i] && ft_strchr("0123456789", str[i]))
		i++;
	if (str[i])
		return (-1);
	else if ((nb_ant = ft_atoi(str)) < 0 || strlen_space(str) > 10)
		return (-2);
	else
		return (nb_ant);
}
