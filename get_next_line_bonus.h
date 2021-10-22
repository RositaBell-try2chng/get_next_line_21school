/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:31:01 by rbell             #+#    #+#             */
/*   Updated: 2021/10/21 14:31:04 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void	rewrite_res(char *new, char *res);
void	rewrite_buff(char *buff, char *src, size_t i, int *flg_n);
char	*give_me_mem(char *res, char *buff, size_t *i, int *flg_n);
char	*create_res(char *res, char *buff, ssize_t *res_read, int *flg_n);
char	*get_next_line(int fd);
#endif
