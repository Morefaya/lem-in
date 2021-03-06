/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nbant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 18:10:13 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/09 20:28:19 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
