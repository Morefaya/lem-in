#include "lem_in.h"

void	del_pipe(t_pipe *pipe, size_t ct)
{
	free(pipe->n_1);
	free(pipe->n_2);
	ft_bzero(pipe, ct);
	free(pipe);
}
