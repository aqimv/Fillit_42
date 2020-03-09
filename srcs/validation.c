/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:27:28 by skennith          #+#    #+#             */
/*   Updated: 2019/12/17 19:27:32 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_matrix(char *buf)
{
	int		i;
	int		count_sh;

	i = 0;
	count_sh = 0;
	while (i < 19)
	{
		if ((i + 1) % 5 != 0 && (buf[i] != '#' && buf[i] != '.'))
			return (0);
		if ((i + 1) % 5 == 0 && buf[i] != '\n')
			return (0);
		if (buf[i] == '#')
			count_sh++;
		i++;
	}
	if ((buf[i] != '\n') || (buf[i + 1] && buf[i] != '\n'))
		return (-1);
	return (count_sh);
}

int			check_shape(char *buf)
{
	int		i;
	int		form_sh;

	i = 0;
	form_sh = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (i + 1 < 20 && buf[i + 1] == '#')
				form_sh++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				form_sh++;
			if (i + 5 < 20 && buf[i + 5] == '#')
				form_sh++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				form_sh++;
		}
		i++;
	}
	return (form_sh);
}

int			validation(char *buf, int size)
{
	int		i;
	int		form_sh;

	i = 0;
	if (size < 20 || size > 545 || ((size + 1) % 21 != 0))
		return (-1);
	while (i <= size)
	{
		if (check_matrix(buf + i) != 4)
			return (-1);
		form_sh = check_shape(buf + i);
		if (form_sh != 6 && form_sh != 8)
			return (-1);
		i += 21;
	}
	return (0);
}
