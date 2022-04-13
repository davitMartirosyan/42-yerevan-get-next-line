/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 06:17:30 by dmartiro          #+#    #+#             */
/*   Updated: 2022/04/13 03:57:47 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"
#include <string.h>
#define BUFFER_SIZE 8

size_t	get_list_size(represent *node)
{
	int	i;

	i = 0;
	while(node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

char	*findnl(const char *buffer, int syb)
{
	char *linetofind;

	linetofind = (char *)buffer;
	while(*linetofind != 0 && *linetofind != syb)
		linetofind++;
	if(*linetofind == syb)
		return (linetofind);
	else
		return (0);
}

void	del_list(represent *link)
{
	represent	*next_node_list;
	while(link)
	{
		next_node_list = link->next;
		free(link);
		link = next_node_list;
	}
}

char *get_string(represent *link)
{
	represent	*lst_addr;
	char		*getline;
	int			c, t;

	lst_addr = link;
	getline = (char *)malloc((sizeof(char) * get_list_size(link) * BUFFER_SIZE) + 1);
	if(!getline)
		return (NULL);
	t = 0;
	while(link)
	{
		c = -1;
		while(link->byteofline[++c])
		{
			getline[t] = link->byteofline[c];
			t++;
		}
		link = link->next;
	}
	getline[t] = '\0';
	del_list(lst_addr);
	return (getline);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

int main(void)
{
	int fd = 3;
	get_next_line(fd);
	return (0);
}


