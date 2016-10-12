#include "lem_in.h"

static void	deal_com(t_list **line_lst, int *i)
{
	char	*str;

	str = ((t_line*)((*line_lst)->content))->line;
	if (*str == '#')
	{
		(*i)++;
		ft_lstrotate(line_lst);
	}
}

t_list		*mk_lstpipe(t_list **line_lst, t_list *r_lst)
{
	t_mk_lstr	data;

	data.i = 0;
	data.r_lst = NULL;
	data.str = ((t_line*)((*line_lst)->content))->line;
	while ((!ch_pipe_format(data.str, r_lst)
		&& data.i < (ft_lstcount(*line_lst) - 1))
		|| (*data.str == '#' && data.i < (ft_lstcount(*line_lst) - 1)))
	{
		deal_com(line_lst, &data.i);
		data.str = ((t_line*)((*line_lst)->content))->line;
		if (!(data.tmp = get_pipe(data.str)))
		{
			ft_lstdel(&data.r_lst, (void(*)(void*, size_t))del_pipe);
			return (NULL);
		}
		if (!data.r_lst)
			ft_lstadd(&data.r_lst, data.tmp);
		else if (!diff_pipe(data.tmp, data.r_lst))
			ft_lstadd_back(data.r_lst, data.tmp);
		else
			ft_lstdel(&data.tmp, (void(*)(void*, size_t))del_pipe);
		ft_lstrotate(line_lst);
		data.str = ((t_line*)((*line_lst)->content))->line;
		(data.i)++;
	}
	return (data.r_lst);
}
