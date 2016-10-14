#include "lem_in.h"

void	del_xion(t_xion *xion, size_t size)
{
	ft_bzero(xion, size);
	free(xion);
}
