#include "lem_in.h"

t_list	*path_cpy(t_list *path)
{
	t_list	*p_cpy;
	t_list	*tmp_1;
	t_list	*tmp_2;
	t_xion	content;

	p_cpy = NULL;
	while (path)
	{
		tmp_1 = ((t_xion*)(path->content))->pipe;
		content.pipe = xion_cpy(tmp_1);
		if (!(tmp_2 = ft_lstnew(&content, sizeof(content))))
		{
			ft_lstdel(&path, (void(*)(void*, size_t))del_path);
			return (NULL);
		}
		if (!p_cpy)
			ft_lstadd(&p_cpy, tmp_2);
		else
			ft_lstadd_back(p_cpy, tmp_2);
		path = path->next;
	}
	return (p_cpy);
}
