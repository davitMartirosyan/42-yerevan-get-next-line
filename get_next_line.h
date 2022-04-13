/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:23:12 by dmartiro          #+#    #+#             */
/*   Updated: 2022/04/13 04:27:27 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct represent
{
    char *byteofline;
    struct represent *prev;
    struct represent *next;
} represent;


char    *get_next_line(int fd);
char	*findnl(const char *buffer, int syb);
char    *get_string(represent *link);
size_t	get_list_size(represent *node);
void	d_list(represent *link);

#endif