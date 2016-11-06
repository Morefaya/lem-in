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

static int	check_ant_pos(t_list *a_lst, t_list *go_in)
{
	t_list	*tmp;

	while (a_lst)
	{
		tmp = ((t_ant*)(a_lst->content))->hill;
		if (tmp == go_in)
			return (1);
		a_lst = a_lst->next;
	}
	return (0);
}

int	deal_move(t_list *ant, t_list *a_lst, t_list *path, t_list *end, int opt)
{
	t_list	*tmp;
	t_list	*way;
	t_list	*pos;
	char	*str;
	int	nu;
	
	nu = ((t_ant*)(ant->content))->nu;
	tmp = ((t_xion*)(path->content))->pipe;
	way = ((t_xion*)(tmp->content))->pipe;
	pos = ((t_ant*)(ant->content))->hill;
	str = ((t_hill*)(way->content))->n;
	while (way != pos)
	{
		tmp = tmp->next;
		way = ((t_xion*)(tmp->content))->pipe;
	}
	tmp = tmp->next;
	if (tmp)
		way = ((t_xion*)(tmp->content))->pipe;
	if ((check_ant_pos(a_lst, way) && way != end)
		|| pos == end)
		return (1);
	str = ((t_hill*)(way->content))->n;
	((t_ant*)(ant->content))->hill = way;
	if (opt & PRINT)
		ft_printf("L%d-%s ", nu, str);
	return (0);
}

void	move_ant(t_list *a_lst, t_list *path, t_list *end, int opt)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	tmp_1 = path;
	tmp_2 = a_lst;
	while (a_lst)
	{
		deal_move(a_lst, tmp_2, path, end, opt);
		path = path->next;
		path = (path) ? path : tmp_1;
		a_lst = a_lst->next;
	}
	if (opt & PRINT)
		ft_putchar('\n');
}

int		solver(t_list **a_lst, t_list **h_lst, t_list **path, int opt)
{
	t_solver	s;

	s.nb_ant = ft_lstcount(*a_lst);
	s.end = get_end(*h_lst);
	s.j = 0;
	if ((opt & PRINT) && (opt & OPT_A))
	{
		print_estate(*h_lst, *a_lst);
		ft_putchar('\n');
	}
	while (check_loop(*a_lst, s.end))
	{
		move_ant(*a_lst, *path, s.end, opt);
		s.j++;
		if ((opt & PRINT) && (opt & OPT_A))
		{
			print_estate(*h_lst, *a_lst);
			if (check_loop(*a_lst, s.end))
				ft_putchar('\n');
		}
	}
	if ((opt & PRINT) && (opt & OPT_B))
		ft_printf("Nombre de tour: %d\n", s.j);
	return (s.j);
}
