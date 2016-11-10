/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:34:25 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/10 15:34:27 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_comb(t_list *comb)
{
	int	i;

	i = 0;
	while (comb && ++i)
	{
		ft_printf("\nCOMBINAISON :%d\n\n", i);
		print_path(((t_xion*)(comb->content))->pipe);
		comb = comb->next;
	}
}
