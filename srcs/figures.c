/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 14:29:12 by skennith          #+#    #+#             */
/*   Updated: 2019/12/24 14:29:16 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			del_figure(char **matrix, t_matrix *elem, int x, int y)
{
	char	**m_elem;
	int		x2;
	int		y2;

	m_elem = elem->matrix;
	x2 = 0;
	while (m_elem[x2])
	{
		y2 = 0;
		while (m_elem[x2][y2])
		{
			if (m_elem[x2][y2] != '.')
				matrix[x + x2][y + y2] = '.';
			y2++;
		}
		x2++;
	}
	return (1);
}

int			rec_figure(char **matrix, t_matrix *elem, int x, int y)
{
	char	**m_elem;
	int		x2;
	int		y2;

	m_elem = elem->matrix;
	x2 = 0;
	while (m_elem[x2])
	{
		y2 = 0;
		while (m_elem[x2][y2])
		{
			if (m_elem[x2][y2] == '#')
				matrix[x + x2][y + y2] = elem->sim;
			y2++;
		}
		x2++;
	}
	return (1);
}

int			check_figure(char **matrix, t_matrix *elem, int x, int y)
{
	char	**m_elem;
	int		x2;
	int		y2;

	m_elem = elem->matrix;
	x2 = 0;
	while (m_elem[x2])
	{
		if (!matrix[x + x2])
			return (0);
		y2 = 0;
		while (m_elem[x2][y2])
		{
			if (!matrix[x + x2][y + y2])
				return (0);
			if (matrix[x + x2][y + y2] != '.' && m_elem[x2][y2] != '.')
				return (0);
			y2++;
		}
		x2++;
	}
	return (rec_figure(matrix, elem, x, y));
}
