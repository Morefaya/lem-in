#include "lem_in.h"

void	print_xion(t_list *xion)
{
	t_list	*tmp;

	while (xion)
	{
		tmp = ((t_xion*)(xion->content))->pipe;
		ft_printf("%p\n", tmp);
		xion = xion->next;
	}
}
