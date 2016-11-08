#include "lem_in.h"

void	init_main(t_main *main)
{
	main->line_lst = NULL;
	main->nb_ant = 0;
	main->len_l = 0;
	main->i = 1;
	main->r_lst = NULL;
	main->p_lst = NULL;
	main->h_lst = NULL;
	main->a_lst = NULL;
	main->w_lst = NULL;
	main->ph_lst = NULL;
	main->s_lst = NULL;
	main->cb_lst = NULL;
	main->max_queue = 0;
	main->opt = 0;
}
