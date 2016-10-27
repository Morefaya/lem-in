#include "lem_in.h"

int	solver(t_list **s_lst, t_list **h_lst, t_list **path)
{
	int	nb_ant;
	int	i;
	t_list	*next;
	t_list	*tmp;

	nb_ant = ft_lstcount(*s_lst);
	i = 0;
	(void)h_lst;
	while (i < nb_ant)
	{
		tmp = ((t_xion*)((*path)->content))->pipe;
		//print_path(*path);
		next = ((t_xion*)(tmp->content))->pipe;
		//ft_printf("pipe : %p\n", next);
		((t_ant*)((*s_lst)->content))->hill = next;
		((t_hill*)(next->content))->a_lst = *s_lst;
		ft_lstrotate(s_lst);
		ft_lstrotate(path);
		i++;
	}
	return (i);
}
