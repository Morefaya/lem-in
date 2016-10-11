/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 21:26:35 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/10 20:30:04 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"

# define START 01
# define END 02
# define NONE 00

typedef struct	s_line
{
	char		*line;
}				t_line;

typedef struct	s_room
{
	char		*n;
	int			cmd;
	int			x;
	int			y;
}				t_room;

typedef struct	s_pipe
{
	char		*n_1;
	char		*n_2;
}				t_pipe;

typedef struct	s_mk_lstr
{
	char		*str;
	int			i;
	t_list		*r_lst;
	t_list		*tmp;
	int			conf;
}				t_mk_lstr;

typedef struct	s_hill
{
	char	*ant;
	char	**pipe;
}		t_hill;

typedef struct	s_ant
{
	char	*n;
}		t_ant;

typedef struct	s_hill
{
	char	*name;
	t_ant	*ant;
	s_hill	*c_xion;
}		t_hill;



void			print_line(t_list *line_lst);
t_list			*get_anthill(void);
int				check_nbant(t_list *lst);
int				strlen_space(char *str);
t_list			*get_room(char *line, int cmd);
int				ch_room_format(char *line);
void			del_room(t_room *room, size_t size);
void			del_line(t_line *room, size_t size);
t_list			*mk_lstroom(t_list **line_lst);
void			print_r_lst(t_list *r_lst);
int				ch_pipe_format(char *line, t_list *r_lst);
int			diff_room(t_list *r_new, t_list *r_lst);
int			diff_pipe(t_list *p_new, t_list *p_lst);
t_list			*get_pipe(char *line);
t_list			*mk_lstpipe(t_list **line_lst, t_list *r_lst);
void			del_pipe(t_pipe *pipe, size_t content);
void			print_p_lst(t_list *p_lst);
#endif
