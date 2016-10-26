#include "lem_in.h"

t_list	*mk_antseek_lst(t_list *a_lst)
{
	t_list	*tmp;
	t_list	*seek_lst;
	t_xion	content;

	seek_lst = NULL;
	while (a_lst)
	{
		content.pipe = a_lst;
		if (!(tmp = ft_lstnew(&content, sizeof(content))))
		{
			ft_lstdel(&seek_lst, (void(*)(void*, size_t))del_xion);
			return (NULL);
		}
		if (!seek_lst)
			ft_lstadd(&seek_lst, tmp);
		else
			ft_lstadd_back(seek_lst, tmp);
		a_lst = a_lst->next;
	}
	return (seek_lst);
}
