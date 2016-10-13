#include "lem_in.h"




static int	check_way(t_list *w_lst, t_list *xion)
{
	t_list	*addr;

	while (w_lst)
	{
		addr = ((t_xion*)(w_lst->content))->pipe;
		if (addr == xion)
			return (1);
		w_lst = w_lst->next;
	}
	return (0);
}

void		path_finder(t_list *h_lst, t_list **w_lst)
{
	t_list	*tmp;
	t_xion	content;
	int		i;
	int		len;

	ft_printf("IN\n");
	content.pipe = h_lst;
	if (!h_lst)
		return ;
	if (!(tmp = ft_lstnew(&content, sizeof(content))))
		return ;
	ft_printf("IN_1\n");
	if (!*w_lst)
		ft_lstadd(w_lst, tmp);
	else
		ft_lstadd_back(*w_lst, tmp);
	ft_printf("IN_2\n");
	/*if (((t_hill*)(h_lst->content))->cmd == END)
	{
		ft_printf("END\n");
		return ;
	}*/
	ft_printf("IN_3\n");
	i = 0;
	ft_printf("%p\n", ((t_hill*)(h_lst->content))->xion);
	len = ft_lstcount(((t_hill*)(h_lst->content))->xion);
	ft_printf("IN_4\n");
	//tmp = ((t_hill*)(h_lst->content))->xion;
	while (i < len)
	{
		ft_printf("IN_5\n");
		//ft_printf("%d", i);
		if (!check_way(*w_lst, ((t_hill*)(h_lst->content))->xion))
		{
			ft_printf("RECUR\n");
			path_finder(((t_hill*)(h_lst->content))->xion, w_lst);
		}
		else
		{
			ft_printf("ROTATE\n");
			//tmp = tmp->next;
			ft_lstrotate(&((t_hill*)(h_lst->content))->xion);
			i++;
		}
	}
}
