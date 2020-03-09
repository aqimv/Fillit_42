/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 20:12:58 by skennith          #+#    #+#             */
/*   Updated: 2019/12/28 18:59:12 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef struct		s_matrix
{
	char			**matrix;
	char			sim;
	struct s_matrix	*next;
}					t_matrix;

t_matrix			*fillit(char *inputfile);
int					validation(char *buf, int size);
t_matrix			*create_list(char **matrix);
int					start(t_matrix *first_elem);
int					check_figure(char **matrix, t_matrix *elem, int x, int y);
int					print_matrix(char **matrix);
int					del_figure(char **matrix, t_matrix *elem, int x, int y);

#endif
