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

represent	*last(represent *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	addback(represent **lst, represent *newnode)
{
	represent	*list;

	if (*lst)
	{
		list = last(*lst);
      list->next = &*newnode;
	}
   else
      *lst = newnode;
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