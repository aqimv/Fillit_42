/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:27:07 by skennith          #+#    #+#             */
/*   Updated: 2020/01/14 16:08:58 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix		*add_matrix(char *buf, int i, int x, int s)
{
	char		str[10];
	int			count_sh;

	count_sh = 0;
	while (i < 20)
	{
		while (buf[s] != '#')
			buf[s++] == '\n' ? i += 5 : i;
		if ((i + 1) % 5 == 0 && count_sh == 4)
			break ;
		buf[i] == '#' ? count_sh++ : count_sh;
		buf[i] == '\n' ? str[x++] = '\n' : str[x];
		if ((i + 5 < 19 && buf[i + 5] == '#') || (i + 10 < 19 && buf[i + 10] \
		== '#') || (buf[i] == '#') || (i - 5 >= 0 && buf[i - 5] == '#') || \
		(i - 10 >= 0 && buf[i - 10] == '#'))
			str[x++] = buf[i];
		i++;
	}
	str[x] = '\0';
	return (create_list(ft_strsplit(str, '\n')));
}

t_matrix		*create_matrix(char *buf, int size)
{
	int			i;
	t_matrix	*first_elem;

	i = 0;
	while (i < size)
	{
		if (!(first_elem = add_matrix(buf + i, 0, 0, 0)))
			return (NULL);
		i += 21;
	}
	return (first_elem);
}

t_matrix		*fillit(char *inputfile)
{
	int			fd;
	int			r;
	char		buf[551];

	fd = open(inputfile, O_RDONLY);
	if ((r = read(fd, buf, 550)) < 0)
		return (NULL);
	close(fd);
	buf[r] = '\0';
	if (validation(buf, r) < 0)
		return (NULL);
	return (create_matrix(buf, r));
}
