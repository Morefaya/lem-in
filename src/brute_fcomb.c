#include "lem_in.h"

t_list	*get_bf_comb(t_list *cb_lst, t_list **a_lst, t_list **h_lst, t_list **ph_lst, t_list **bf_comb)
{
	t_list	*tmp_1;
	int	ret;
	int	low;

	low = MAX_INT;
	while (cb_lst)
	{
		tmp_1 = ((t_xion*)(cb_lst->content))->pipe;
		if ((ret = solver(a_lst, h_lst, tmp_1)) < low)
		{
			ft_lstdel(bf_comb, (void(*)(void*, size_t))del_xion);
			*bf_comb = xion_cpy(tmp_1);
		}
		cb_lst = cb_lst->next;
	}
}

t_list	*brute_fcomb(t_list **a_lst, t_list **h_lst, t_list **ph_lst, int max)
{
	int	i;
	int	tmp;
	t_list	*bf_comb;
	t_list	*cb_lst;

	tmp = 0;
	i = 1;
	while (i <= max)
	{
		cb_lst = mk_comb(*ph_lst, i);
		get_bf_comb(cb_lst, a_lst, h_lst, ph_lst, &bf_comb);
		ft_lstdel(&cb_lst, (void(*)(void*, size_t))del_path);
		i++;
	}
	return ();
}
