/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 14:22:57 by skennith          #+#    #+#             */
/*   Updated: 2019/12/24 14:23:04 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			matrix_free(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		ft_strdel(&matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
	return (0);
}

char		**create_square(int num)
{
	char	**matrix;
	int		i;

	i = 0;
	if (!(matrix = (char **)malloc(sizeof(char *) * num + 1)))
		return (NULL);
	while (i < num)
	{
		matrix[i] = ft_strnew(num);
		matrix[i] = ft_memset(matrix[i], '.', num);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

int			number_of_figures(t_matrix *first_elem)
{
	int		count;

	count = 0;
	while (first_elem != NULL)
	{
		count++;
		first_elem = first_elem->next;
	}
	return (count);
}

int			recursion(char **matrix, t_matrix *elem, int check)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	while (matrix[x] && !check)
	{
		y = 0;
		while (matrix[x][y] && !check)
		{
			if ((i = check_figure(matrix, elem, x, y)) && elem->next)
			{
				check = recursion(matrix, elem->next, check);
				if (!check)
					del_figure(matrix, elem, x, y);
			}
			if (i && !elem->next)
				check++;
			y++;
		}
		x++;
	}
	return (check);
}

int			start(t_matrix *first_elem)
{
	int		num;
	char	**matrix;
	int		rec;

	num = number_of_figures(first_elem);
	num = ft_sqrt(num * 4);
	if (!(matrix = create_square(num)))
		return (-1);
	rec = recursion(matrix, first_elem, 0);
	num++;
	while (rec == 0)
	{
		matrix_free(matrix);
		if (!(matrix = create_square(num)))
			return (-1);
		rec = recursion(matrix, first_elem, 0);
		num++;
	}
	print_matrix(matrix);
	matrix_free(matrix);
	return (0);
}
