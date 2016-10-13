/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 19:23:34 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/13 20:58:46 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char		*cmp_name(t_list *h_lst, t_list *p_lst)
{
	char	*n;
	char	*n_1;
	char	*n_2;

	n = ((t_hill*)(h_lst->content))->n;
	n_1 = ((t_pipe*)(p_lst->content))->n_1;
	n_2 = ((t_pipe*)(p_lst->content))->n_2;
	if (!ft_strcmp(n, n_1))
		return (n_1);
	else if (!ft_strcmp(n, n_2))
		return (n_2);
	return (NULL);
}

static int		count_nbpipe(t_list *h_lst, t_list *p_lst)
{
	int	ret;

	ret = 0;
	while (p_lst)
	{
		if (cmp_name(h_lst, p_lst))
			ret++;
		p_lst = p_lst->next;
	}
	ft_printf("ret : %d\n", ret);
	return (ret);
}

static t_list	**mk_tab(t_list *h_lst, t_list *p_lst)
{
	int		nb_p;
	t_list	**tab;
	char	*n;
	int		i;

	nb_p = count_nbpipe(h_lst, p_lst);
	if (!(tab = (t_list**)malloc(sizeof(*tab) * (nb_p + 1))))
		return (NULL);
	i = 0;
	while (p_lst && i < nb_p)
	{
		if ((n = cmp_name(h_lst, p_lst)))
		{
			tab[i] = get_addr_hill(n, h_lst);
			ft_printf("cest %s\n");
			i++;
		}
		p_lst = p_lst->next;
	}
	tab[i] = NULL;
	ft_printf("\n");
	return (tab);
}

void		mk_pipe(t_list *h_lst, t_list *p_lst)
{
	while (h_lst)
	{
		((t_hill*)(h_lst->content))->pipe = mk_tab(h_lst, p_lst);
		h_lst = h_lst->next;
	}
}
