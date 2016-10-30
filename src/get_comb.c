#include "lem_in.h"

int	init_1(t_get_comb *data, t_list *path, int nb)
{
	if ((data->len = ft_lstcount(path)) < nb)
		return (1);
	data->comb = NULL;
	data->tmp_1 = path;
	data->i = 0;
	return (0);
}

void	init_2(t_get_comb *data)
{
	data->tmp_2 = data->tmp_1;
	data->tmp_4 = NULL;
	data->j = 0;
}

int	add_comb(t_list *t_1, t_list **tmp_4)
{
	t_xion	content;
	t_list	*tmp;

	content.pipe = t_1;
	if (!(tmp = ft_lstnew(&content, sizeof(content))))
		return (1);
	if (!*tmp_4)
		ft_lstadd(tmp_4, tmp);
	else
		ft_lstadd_back(*tmp_4, tmp);
	return (0);
}

t_list	*get_comb(t_list *path, int nb)
{
	t_get_comb	data;

	if (init_1(&data, path, nb))
		return (NULL);
	while (data.i < nb)
	{
		init_2(&data);
		while (data.j < data.len - nb + 1)
		{
			data.tmp_3 = ((t_xion*)(data.tmp_2->content))->pipe;
			if (add_comb(data.tmp_3, &data.tmp_4))
			{
				return (NULL);
			}
			data.tmp_2 = data.tmp_2->next;
			data.j++;
		}
		if (add_comb(data.tmp_4, &data.comb))
		{
			ft_lstdel(&data.comb, (void(*)(void*, size_t))del_xion);
			return (NULL);
		}
		data.tmp_1 = data.tmp_1->next;
		data.i++;
	}
	return (data.comb);
}
