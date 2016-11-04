#include "lem_in.h"

static void	get_bf_comb(t_list *cb_lst, t_list **h_lst, int nb_ant, t_list **bf_comb, int *low, int opt)
{
	t_list	**tmp_1;
	int	ret;
	t_list	*a_lst;

	while (cb_lst)
	{
		tmp_1 = &((t_xion*)(cb_lst->content))->pipe;
		a_lst = get_antlst(nb_ant, *h_lst);
		if ((ret = solver(&a_lst, h_lst, tmp_1, opt)) < *low)
		{
			*low = ret;
			ft_lstdel(bf_comb, (void(*)(void*, size_t))del_path);
			*bf_comb = path_cpy(*tmp_1);
		}
		ft_lstdel(&a_lst, (void(*)(void*, size_t))del_ant);
		cb_lst = cb_lst->next;
	}
}

t_list	*brute_fcomb(t_list **h_lst, t_list **ph_lst, int nb_ant, int max, int opt)
{
	int	i;
	int	tmp;
	t_list	*bf_comb;
	t_list	*cb_lst;
	int	low;

	tmp = 0;
	i = 1;
	bf_comb = NULL;
	low = MAX_INT;
	while (i <= max)
	{
		cb_lst = mk_comb(*ph_lst, i);
		get_bf_comb(cb_lst, h_lst, nb_ant, &bf_comb, &low, opt);
		ft_lstdel(&cb_lst, (void(*)(void*, size_t))del_path);
		i++;
	}
	return (bf_comb);
}
