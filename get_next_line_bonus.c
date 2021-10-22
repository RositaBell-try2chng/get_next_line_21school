/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:30:28 by rbell             #+#    #+#             */
/*   Updated: 2021/10/21 14:30:50 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*res;
	static char	buffs[OPEN_MAX][BUFFER_SIZE + 1];
	int			flg_n;
	ssize_t		res_read;

	flg_n = 0;
	res_read = BUFFER_SIZE;
	res = NULL;
	while (!flg_n && res_read > 0 && fd >= 0 && fd <= OPEN_MAX)
	{
		if (0 == buffs[fd][0])
		{
			res_read = read(fd, buffs[fd], BUFFER_SIZE);
			if (res_read < 0)
			{
				free(res);
				return (NULL);
			}
			buffs[fd][res_read] = '\0';
		}
		else
			res = create_res(res, buffs[fd], &res_read, &flg_n);
	}
	return (res);
}
