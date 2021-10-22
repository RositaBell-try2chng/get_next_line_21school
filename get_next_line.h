/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:31:22 by rbell             #+#    #+#             */
/*   Updated: 2021/10/20 10:46:26 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void	rewrite_res(char *new, char *res);
void	prepare(int *flg_n, ssize_t *res_read, char **res, char **buffs);
int		read_me(int fd, char *buffs, char *res);
void	rewrite_buff(char *buff, char *src, size_t i, int *flg_n);
char	*give_me_mem(char *res, char *buff, size_t *i, int *flg_n);
char	*create_res(char *res, char *buff, ssize_t *res_read, int *flg_n);
char	*get_next_line(int fd);
#endif