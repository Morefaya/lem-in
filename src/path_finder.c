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


static void	add_path(t_list **w_lst, t_list **ph_lst)
{
	t_list	*tmp;
	t_xion	content;

	content.pipe = xion_cpy(*w_lst);
	if (!(tmp = ft_lstnew(&content, sizeof(content))))
		return ;
	if (!*ph_lst)
		ft_lstadd(ph_lst, tmp);
	else
		ft_lstadd_back(*ph_lst, tmp);
}
/*
void		path_finder(t_list *h_lst, t_list **w_lst, t_list **ph_lst, t_list **as_lst)
{
	char	*str;
	int	nb;
	t_list	*xion;
	t_list	*w;
	t_list	*pipe;
	t_list	*tmp;
	
	if (!*w_lst)
		add_way(h_lst, w_lst);
	str = ((t_hill*)(h_lst->content))->n;
	nb = ((t_hill*)(h_lst->content))->cmd;
	xion = ((t_hill*)(h_lst->content))->xion;
	w = ((t_xion*)((*w_lst)->content))->pipe;
	ft_printf("%s : %p\tcmd :%d\n", str, h_lst, nb);
	if (nb == END)
	{
		add_path(w_lst, ph_lst);
		ft_printf("ADD_PATH\n");
		//print_xion(*w_lst);
		return ;
	}
	while (xion && check_way(((t_xion*)(xion->content))->pipe, *w_lst))
		xion = xion->next;
	if (xion)
	{
		add_way(((t_xion*)(xion->content))->pipe, w_lst);
		path_finder(((t_xion*)(xion->content))->pipe, w_lst, ph_lst);
	}
	while (xion)
	{
		while (xion && check_way(((t_xion*)(xion->content))->pipe, *w_lst)
			&& check_way(((t_xion*)(xion->content))->pipe, *as_lst))
		{
			ft_printf("xion->next\n");
			xion = xion->next;
		}
		if (xion)
		{
			pipe = ((t_xion*)(xion->content))->pipe;
			add_way(pipe, w_lst);
			if (!check_way(((t_xion*)(xion->content))->pipe, *w_lst) &&
				check_way(((t_xion*)(xion->content))->pipe, *as_lst))
				path_finder(pipe, w_lst, ph_lst, as_lst);
			tmp = ((t_xion*)((*w_lst)->content))->pipe;
			if (((t_hill*)(tmp->content))->cmd != END)
			{
				ft_lstrev_rotate(w_lst);
				ft_lstpush(w_lst, as_lst);
			}	
		}	
		if ((xion && !check_way(((t_xion*)(xion->content))->pipe, *w_lst))
			|| (xion && !check_way(((t_xion*)(xion->content))->pipe, *as_lst)))
			xion = xion->next;
	}
}*/


int		path_finder(t_list *h_lst, t_list **w_lst, t_list **ph_lst, int i)
{
	char	*str;
	t_list	*xion;
	t_list	*pipe;
	t_list	*done;
	int	ret;

	done = NULL;
	ret = 0;
	add_way(h_lst, w_lst);
	ft_printf("in => stack n_%d\n", i);
	if (((t_hill*)(h_lst->content))->cmd == END)
	{
		ft_printf("end\n");
		add_path(w_lst, ph_lst);
		//ft_lstdel_range(w_lst, ft_lstcount(*w_lst), (void(*)(void*, size_t))del_xion);
		return (1);
	}
	str = ((t_hill*)(h_lst->content))->n;
	xion = ((t_hill*)(h_lst->content))->xion;
	pipe = ((t_xion*)(xion->content))->pipe;
	while (xion)
	{
		pipe = ((t_xion*)(xion->content))->pipe;
		if (xion && !check_way(pipe, *w_lst) && !check_way(pipe, done))
		{
			add_way(pipe, &done);
			ret = path_finder(pipe, w_lst, ph_lst, i + 1);
		}
		else if ((xion && check_way(pipe, *w_lst)) ||
			(xion && check_way(pipe, done)))
			xion = xion->next;
	}
	if (!xion)
	{
		//ft_lstdel(&done, (void(*)(void*, size_t))del_xion);
		add_path(w_lst, ph_lst);
	}
	//ft_lstdel_range(w_lst, ft_lstcount(*w_lst), (void(*)(void*, size_t))del_xion);
	ft_printf("out <= stack n_%d\n", i);
	return (0);
}
