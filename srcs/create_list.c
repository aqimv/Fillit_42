/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:27:39 by skennith          #+#    #+#             */
/*   Updated: 2019/12/17 19:27:42 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix			*new_list(char **matrix, char sim)
{
	t_matrix		*new_elem;

	new_elem = (t_matrix *)malloc(sizeof(t_matrix));
	new_elem->matrix = matrix;
	new_elem->sim = sim;
	new_elem->next = NULL;
	return (new_elem);
}

t_matrix			*create_list(char **matrix)
{
	static t_matrix	*first_elem;
	t_matrix		*tmp;
	char			sim;

	sim = 'A';
	tmp = first_elem;
	if (!first_elem)
	{
		first_elem = new_list(matrix, sim);
		return (first_elem);
	}
	else
	{
		sim++;
		while (tmp->next)
		{
			tmp = tmp->next;
			sim++;
		}
		tmp->next = new_list(matrix, sim);
	}
	return (first_elem);
}
