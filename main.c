/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 06:17:30 by dmartiro          #+#    #+#             */
/*   Updated: 2022/04/11 05:49:30 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"
#include <string.h>
#define BUFFER_SIZE 8

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

size_t	get_list_length(represent *node)
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

int get_line(represent *link)
{
	char	*newstring;
	size_t	nodes;
	size_t	c;
	size_t	i;
	nodes = get_list_length(link);
	newstring = malloc(sizeof(char) * (nodes * (BUFFER_SIZE + 1)));
	while(i < nodes)
	{
		c = 0;
		while(link->byteofline)
		{
			newstring[c] = link->byteofline[c];
			link = link->next;
			c++;
			if()
		}
		i++;
	}
	return (nodes);
}

int main(void)
{
	represent *line;
	line = (represent *)malloc(sizeof(represent));
	line->byteofline = "Lorem Ip";
	line->prev = NULL;
	
	line->next = (represent *)malloc(sizeof(represent));
	line->next->prev = line;
	line->next->byteofline = "sum is s";
	line->next->next = NULL;

	
	printf("%d", get_line(line));
	return (0);
}


