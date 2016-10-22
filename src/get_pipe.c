#include "lem_in.h"

static int	get_name_1(char *line, t_pipe *pipe)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && ft_strchr(" \t", line[i]))
		i++;
	while (line[i + j] && !ft_strchr(" \t-", line[i + j]))
		j++;
	if (!(pipe->n_1 = ft_strsub(line, i, j)))
		return (-1);
	return (i + j);
}

static int	get_name_2(char *line, t_pipe *pipe, int i)
{
	int	j;

	j = 0;
	while (line[i] && ft_strchr(" \t", line[i]))
		i++;
	if (line[i] == '-')
		i++;
	while (line[i] && ft_strchr(" \t", line[i]))
		i++;
	while (line[i + j] && !ft_strchr(" \t-", line[i + j]))
		j++;
	if (!(pipe->n_2 = ft_strsub(line, i, j)))
		return (-1);
	return (i + j);
}

t_list		*get_pipe(char *line, t_list *r_lst)
{
	t_list	*p_lst;
	t_pipe	content;
	int	i;

	if (ch_pipe_format(line, r_lst))
		return (NULL);
	if ((i = get_name_1(line, &content)) == -1)
		return (NULL);
	else if (get_name_2(line, &content, i) == -1)
	{
		free(content.n_1);
		return (NULL);
	}
	if (!(p_lst = ft_lstnew(&content, sizeof(content))))
	{
		free(content.n_1);
		free(content.n_2);
		return (NULL);
	}
	return (p_lst);
}
