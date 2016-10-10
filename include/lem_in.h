/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 21:26:35 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/09 20:28:50 by jcazako          ###   ########.fr       */
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

void	print_line(t_list *line_lst);
t_list	*get_anthill(void);
int		check_nbant(t_list *lst);
int		strlen_space(char *str);
t_list		*get_room(char *line, int cmd);
#endif
