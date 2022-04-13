/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:22:28 by dmartiro          #+#    #+#             */
/*   Updated: 2022/04/13 04:22:22 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 5

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

//return size of linked list [-][-][-] ----> 3
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

//return joined string from all nodes  [<-][a][->] - [<-][b][->] - [<-][c][->] ----> abc
char *get_string(represent *link)
{
	represent	*lst_addr;
	char		*getline;
	int			c;
	int			t;

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
	d_list(lst_addr);
	return (getline);
}

//free list
void	d_list(represent *link)
{
	represent	*next_node_list;
	while(link)
	{
		next_node_list = link->next;
		free(link);
		link = next_node_list;
	}
}