#include "lem_in.h"

void	del_path(t_xion *path, size_t size)
{
	ft_lstdel(&path->pipe, (void(*)(void*, size_t))del_xion);
	ft_bzero(path, size);
	free(path);
}
