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

/*int		solver(t_list **s_lst, t_list **h_lst, t_list **path)
{
	int	nb_ant;
	int	i;
	int	j;
	t_list	*next;
	t_list	*tmp_1;
	t_list	*tmp_2;
	t_list	*end;

	nb_ant = ft_lstcount(*s_lst);
	end = get_end(*h_lst);
	check_loop(*s_lst, end);
	ft_printf("ants:\n");
	print_ant(((t_xion*)((*s_lst)->content))->pipe);
	while (check_loop(*s_lst, end))
	{
		i = 0;
		while (i < nb_ant)
		{
			tmp_1 = ((t_xion*)((*path)->content))->pipe;
			tmp_2 = ((t_xion*)((*s_lst)->content))->pipe;
			next = ((t_xion*)(tmp_1->content))->pipe;
			j = 0;
			while (next && next != ((t_xion*)(tmp_2->content))->pipe)
			{
				//ft_printf("%p\n", next);
				ft_printf("%p\t%p\n", next, ((t_xion*)(tmp_2->content))->pipe);
				next = next->next;
				j++;
			}
			if (1)//(j && next)
			{
				next = next->next;
				ft_printf("pipe : %p\n", next);
				if (!((t_hill*)(next->content))->a_lst)
				{
					((t_ant*)((*s_lst)->content))->hill = next;
					((t_hill*)(next->content))->a_lst = *s_lst;
				}
			}
			else
				ft_printf("no\n");
			ft_lstrotate(s_lst);
			ft_lstrotate(path);
			i++;
		}
	}
	return (i);
}*/


int		solver(t_list **a_lst, t_list **h_lst, t_list **path)
{
	int		nb_ant;
	int		i;
	t_list	*tmp_1;
	t_list	*tmp_2;
	t_list	*end;

	nb_ant = ft_lstcount(*a_lst);
	end = get_end(*h_lst);
	check_loop(*a_lst, end);
	i = 0;
	(void)path;
	print_hill(*h_lst);
	while (i < nb_ant)
	{
		tmp_1 = ((t_xion*)((*path)->content))->pipe;
		tmp_2 = ((t_xion*)(tmp_1->content))->pipe;
	
		ft_printf("tmp_1 : %p\ttmp_2 : %p\ttmp_2->next : %p\n", tmp_1, tmp_2, tmp_2->next);
		//print_ant(*a_lst);
		//ft_printf("\n");
		ft_lstrotate(a_lst);
		print_path(*path);
		ft_printf("WWWWWWWWWWWW\n");
		ft_printf("\n");
		ft_lstrotate(path);
		i++;
	}

	return (i);
}
