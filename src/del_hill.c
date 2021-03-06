/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_hill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:58:36 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/12 18:17:18 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_hill(t_hill *hill, size_t ct)
{
	ft_lstdel(&hill->xion, (void(*)(void*, size_t))del_xion);
	free(hill);
	ft_bzero(hill, ct);
}
