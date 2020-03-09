/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:25:46 by skennith          #+#    #+#             */
/*   Updated: 2019/11/28 13:25:48 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				print_matrix(char **matrix)
{
	int			i;

	i = 0;
	while (matrix[i] != NULL)
	{
		ft_putstr(matrix[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_matrix	*first_elem;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (-1);
	}
	if ((first_elem = fillit(av[1])) == NULL)
	{
		ft_putstr("error\n");
		return (-1);
	}
	start(first_elem);
	return (0);
}
