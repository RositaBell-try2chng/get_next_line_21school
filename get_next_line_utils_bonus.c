/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:31:34 by rbell             #+#    #+#             */
/*   Updated: 2021/10/21 14:31:39 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	rewrite_res(char *new, char *res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		new[i] = res[i];
		i++;
	}
	new[i] = '\0';
}

void	rewrite_buff(char *buff, char *src, size_t i, int *flg_n)
{
	if (buff[0] == '\0')
		return ;
	while (src[i + *flg_n])
	{
		buff[i] = src[i + *flg_n];
		i++;
	}
	buff[i] = '\0';
}

char	*give_me_mem(char *res, char *buff, size_t *i, int *flg_n)
{
	char	*new;
	ssize_t	j;

	j = 0;
	while (buff[j] && buff[j] != '\n')
		j++;
	if (buff[j] == '\n')
		*flg_n = 1;
	if (NULL == res)
		new = malloc(sizeof(char) * (j + *flg_n + 1));
	else
	{
		while (res[*i])
			*i = *i + 1;
		new = malloc(sizeof(char) * (*i + j + *flg_n + 1));
		if (NULL == new)
		{
			free(res);
			return (NULL);
		}
		rewrite_res(new, res);
		free(res);
	}
	return (new);
}

char	*create_res(char *res, char *buff, ssize_t *res_read, int *flg_n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	res = give_me_mem(res, buff, &i, flg_n);
	if (NULL == res)
	{
		*res_read = 0;
		return (NULL);
	}
	while (buff[++j] != '\n' && buff[j])
		res[i + j] = buff[j];
	if (buff[j] == '\n')
	{
		res[i + j] = '\n';
		res[i + j + 1] = '\0';
	}
	else
		res[i + j] = '\0';
	rewrite_buff(buff, (buff + j), 0, flg_n);
	return (res);
}
