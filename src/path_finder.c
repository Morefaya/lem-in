#include "lem_in.h"

static int	check_way(t_list *pipe, t_list *w_lst)
{
	t_list	*addr;

	while (w_lst)
	{
		addr = ((t_xion*)(w_lst->content))->pipe;
		if (addr == pipe)
			return (1);
		w_lst = w_lst->next;
	}
	return (0);
}

static void	add_way(t_list *h_lst, t_list **w_lst)
{
	t_list	*tmp;
	t_xion	content;

	content.pipe = h_lst;
	if (!(tmp = ft_lstnew(&content, sizeof(content))))
		return ;
	if (!*w_lst)
		ft_lstadd(w_lst, tmp);
	else
		ft_lstadd_back(*w_lst, tmp);
}

void		path_finder(t_list *h_lst, t_list **w_lst)
{
	char	*str;
	int	nb;
	t_list	*xion;
	t_list	*pipe;
	
	add_way(h_lst, w_lst);
	str = ((t_hill*)(h_lst->content))->n;
	nb = ((t_hill*)(h_lst->content))->cmd;
	xion = ((t_hill*)(h_lst->content))->xion;
	//ft_printf("%s : %p\tcmd :%d\n", str, h_lst, nb);
	while (xion)
	{
		pipe = ((t_xion*)(xion->content))->pipe;
		if (!check_way(pipe, *w_lst))
			path_finder(pipe, w_lst);
		xion = xion->next;
	}
}
