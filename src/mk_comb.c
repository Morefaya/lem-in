#include "lem_in.h"

void	add_shot(t_list **shot, t_list *cb_idx)
{
	t_list	*tmp;
	t_list	*tmp_1;
	t_list	*tmp_2;
	t_xion	content;
	
	tmp_1 = ((t_xion*)(cb_idx->content))->pipe;
	tmp_2 = ((t_xion*)(tmp_1->content))->pipe;
	content.pipe = tmp_1;
	if (!(tmp = ft_lstnew(&content, sizeof(content))))
		return ;
	if (!*shot)
		ft_lstadd(shot, tmp);
	else
		ft_lstadd_back(*shot, tmp);	
}

void	rec_comb(t_list **shot, t_list **cb_lst)
{
	t_list	*tmp;
	t_xion	content;

	content.pipe = xion_cpy(*shot);
	if (!(tmp = ft_lstnew(&content, sizeof(content))))
		return ;
	if (!*cb_lst)
		ft_lstadd(cb_lst, tmp);
	else
		ft_lstadd_back(*cb_lst, tmp);
}

void	jump(t_recu_comb data, t_list *tmp_1, int i)
{
	int	len;

	add_shot(data.shot, tmp_1);
	data.cb_idx = data.cb_idx->next;
	data.nb--;
	data.index = i;
	recu_comb(data);
	len = ft_lstcount(*data.shot);
	ft_lstdel_range(data.shot, len, (void(*)(void*, size_t))del_xion);
}

void	recu_comb(t_recu_comb data)
{
	int	i;
	t_list	*tmp_1;

	if (!data.nb)
	{
		rec_comb(data.shot, data.cb_lst);
		return ;
	}
	tmp_1 = ((t_xion*)(data.cb_idx->content))->pipe;
	i = 0;
	while (tmp_1)
	{
		if (i >= data.index)
			jump(data, tmp_1, i);
		tmp_1 = tmp_1->next;
		i++;
	}
}

t_list	*mk_comb(t_list *path, int nb)
{
	t_list		*cb_idx;
	t_list		*cb_lst;
	t_list		*shot;
	t_recu_comb	data;

	if (!(cb_idx = get_comb(path, nb)))
		return (NULL);
	shot = NULL;
	cb_lst = NULL;
	data.cb_idx = cb_idx;
	data.shot = &shot;
	data.cb_lst = &cb_lst;
	data.nb = nb;
	data.index = 0;
	recu_comb(data);
	ft_lstdel(&cb_idx, (void(*)(void*, size_t))del_path);
	ft_lstdel(&shot, (void(*)(void*, size_t))del_path);
	return (cb_lst);
}
