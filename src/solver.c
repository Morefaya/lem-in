#include "lem_in.h"

static t_list	*get_end(t_list *h_lst)
{
	while (h_lst)
	{
		if (((t_hill*)(h_lst->content))->cmd == END)
			return (h_lst);
		h_lst = h_lst->next;
	}
	return (NULL);
}

static int	check_loop(t_list *s_lst, t_list *end)
{
	while (s_lst)
	{
		if (((t_ant*)(s_lst->content))->hill != end)
			return (1);
		s_lst = s_lst->next;
	}
	return (0);
}

int		solver(t_list **a_lst, t_list **h_lst, t_list **path)
{
	int	nb_ant;
	int	i;
	int	j;
	t_list	*tmp_1;
	t_list	*tmp_2;
	t_list	*tmp_3;
	t_list	*end;

	nb_ant = ft_lstcount(*a_lst);
	end = get_end(*h_lst);
	tmp_3 = NULL;
	i = 0;
	j = 0;
	while (check_loop(*a_lst, end))
	{	
		while (i < nb_ant)
		{
			tmp_1 = ((t_xion*)((*path)->content))->pipe;
			tmp_2 = ((t_xion*)(tmp_1->content))->pipe;
			while (tmp_1 && tmp_2 != ((t_ant*)((*a_lst)->content))->hill)
			{
				tmp_1 = tmp_1->next;
				if (tmp_1)
					tmp_2 = ((t_xion*)(tmp_1->content))->pipe;
			}
			if (tmp_1)
			{
				tmp_1 = tmp_1->next;
				if (tmp_1)
					tmp_2 = ((t_xion*)(tmp_1->content))->pipe;
			}
			if (tmp_2 == end || !((t_hill*)(tmp_2->content))->a_lst)
			{
				((t_ant*)((*a_lst)->content))->hill = tmp_2;
				((t_hill*)(tmp_2->content))->a_lst = *a_lst;
				if (tmp_3)
					((t_hill*)(tmp_3->content))->a_lst = NULL;
			}
			tmp_3 = tmp_2;
			ft_lstrotate(a_lst);
			ft_lstrotate(path);
			i++;
		}
		while (i)
		{
			ft_lstrev_rotate(path);
			i--;
		}
		print_ant(*a_lst);
		ft_printf("\n");
		j++;
	}
	return (j);
}
