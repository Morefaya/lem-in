#include "lem_in.h"

int	solver(t_list **s_lst, t_list **h_lst, t_list *path)
{
	int	nb_ant;
	int	i;

	nb_ant = ft_lstcount(*s_lst);
	i = 0;
	while (i < nb_ant)
	{
		
		ft_lstrotate(s_lst);
		i++;
	}
	
}
