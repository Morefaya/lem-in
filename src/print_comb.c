#include "lem_in.h"

void	print_comb(t_list *comb)
{
	int	i;

	i = 0;
	while (comb && ++i)
	{
		ft_printf("\nCOMBINAISON :%d\n\n", i);
		print_path(((t_xion*)(comb->content))->pipe);
		comb = comb->next;
	}
}
