/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:30:53 by rbell             #+#    #+#             */
/*   Updated: 2021/10/21 13:48:34 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*res;
	static char		*buffs;
	int				flg_n;
	ssize_t			res_read;

	if (read(fd, buffs, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	prepare(&flg_n, &res_read, &res, &buffs);
	while (!flg_n && res_read > 0 && fd >= 0 && fd <= OPEN_MAX)
	{
		if (0 == buffs[0])
			res_read = read_me(fd, buffs, res);
		else
			res = create_res(res, buffs, &res_read, &flg_n);
	}
	if (buffs[0] == 0 && res_read == 0)
	{
		free(buffs);
		buffs = NULL;
	}
	return (res);
}

void	prepare(int *flg_n, ssize_t *res_read, char **res, char **buffs)
{
	*flg_n = 0;
	*res_read = BUFFER_SIZE;
	*res = NULL;
	if (*buffs == NULL)
	{
		*buffs = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		*buffs[0] = 0;
	}
}

int	read_me(int fd, char *buffs, char *res)
{
	int	res_read;

	res_read = read(fd, buffs, BUFFER_SIZE);
	if (res_read >= 0)
		buffs[res_read] = 0;
	else
		free(res);
	return (res_read);
}
