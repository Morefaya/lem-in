/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_fcomb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:02:26 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/09 16:30:33 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	get_bf_comb(t_bf_comb *a)
{
	t_list	**tmp_1;
	int		ret;
	t_list	*a_lst;
	t_list	*cb_lst;

	cb_lst = a->cb_lst;
	while (cb_lst)
	{
		tmp_1 = &((t_xion*)(cb_lst->content))->pipe;
		a_lst = get_antlst(a->nb_ant, *a->h_lst);
		if ((ret = solver(&a_lst, a->h_lst, tmp_1, 0)) < *a->low)
		{
			*a->low = ret;
			ft_lstdel(a->bf_comb, (void(*)(void*, size_t))del_path);
			*a->bf_comb = path_cpy(*tmp_1);
		}
		ft_lstdel(&a_lst, (void(*)(void*, size_t))del_ant);
		cb_lst = cb_lst->next;
	}
}

t_list		*brute_fcomb(t_list **h_lst, t_list **ph_lst, int nb_ant, int max)
{
	int			i;
	t_list		*bf_comb;
	t_list		*cb_lst;
	int			low;
	t_bf_comb	a;

	i = 1;
	bf_comb = NULL;
	low = MAX_INT;
	a.cb_lst = NULL;
	a.h_lst = h_lst;
	a.low = &low;
	a.nb_ant = nb_ant;
	a.bf_comb = &bf_comb;
	while (i <= max)
	{
		a.cb_lst = mk_comb(*ph_lst, i);
		get_bf_comb(&a);
		ft_lstdel(&cb_lst, (void(*)(void*, size_t))del_path);
		i++;
	}
	return (bf_comb);
}
