/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:21:53 by dmartiro          #+#    #+#             */
/*   Updated: 2022/04/13 05:07:41 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *line_by_line(const char *string)
{
   char *str;
   char *getline;
   int i;

   i = 0;
   while(string[i] && string[i] != '\n')
      i++;
   getline = (char *)malloc(sizeof(char) * (i + 2));
   i = 0;
   while(string[i] && string[i] != '\n')
   {
      getline[i] = string[i];
      i++;
   }
   if(string[i] && string[i] == '\n')
      getline[i++] = '\n';
   getline[i++] = '\0';
   return (getline);
}

//return joined string from all nodes  [<-][a][->] - [<-][b][->] - [<-][c][->] ----> abc
char *get_string(represent *link, int *readed)
{
	represent	*lst_addr;
	char		*getline;
	int			c;
	int			t;

	lst_addr = link;
	
	if(!(getline = (char *)malloc((sizeof(char) * (*readed + 1)))))
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

void  create_buff_list(int fd, represent **list, int *readed)
{
   char *buffer;
   int rd;
   if(!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
      return ;
   while((rd = read(fd, buffer, BUFFER_SIZE)))
   {
      buffer[rd] = '\0';
      struct represent *node;
      node = (represent *)malloc(sizeof(represent));
      node->byteofline = buffer;
      node->next = NULL;
      // printf("%s", node->byteofline);
      addback(list, node);
      if(findnl(buffer, '\n'))
         break;
      node = node->next;
   }
   free(buffer);
}

char    *get_next_line(int fd)
{
    static char         *truck;
    char                *string;
    char                *oneline;
    struct represent    *list;
    int                 readed;
    
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
   readed = 0;
   list = (represent *)malloc(sizeof(represent));
   list->byteofline = truck;
   list->next = NULL;
   create_buff_list(fd, &list, &readed);
   printf("%s", list->next->byteofline);
   // string = get_string(list, &readed);
   // oneline = line_by_line(string);
   // truck = findnl(string, '\n');
   return (string);
}


int main(void)
{
   int fd = open("file.txt", O_RDONLY);
   get_next_line(fd);
}











 /*
 static char *truck;
    char        *string;
    char        *oneline;
    represent   *list;
    
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    list = create_buff_list(fd, truck);
    string = get_string(list);
    oneline = line_by_line(string);
    truck = findnl(string, '\n');
    return (oneline);
    */