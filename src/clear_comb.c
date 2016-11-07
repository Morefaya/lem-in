#include "lem_in.h"


static int	check_comb(t_list *comb)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	tmp_1 = ((t_xion*)(comb->content))->pipe;
	tmp_2 = ((t_xion*)(tmp_1->content))->pipe;
	while (tmp_1)
	{
		tmp_2 = XION(XION(tmp_1)->next);
		ft_printf("%p\t%p\n", tmp_1, tmp_2);
		tmp_1 = tmp_1->next;
	}
	return (0);
}

void	clear_comb(t_list **cb_lst)
{
	t_list	*tmp;
	int	i;

	//print_comb(*cb_lst);
	tmp = *cb_lst;
	i = 0;
	while (tmp)
	{
		check_comb(tmp);
		tmp = tmp->next;
		i++;
	}
}
