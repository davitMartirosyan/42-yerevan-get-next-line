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

represent   *create_buff_list(int fd, char *truck)
{
   represent *list;
   represent *back;
   int rd;
   char *buffer;

   buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
   list = (represent *)malloc(sizeof(represent));
   list->byteofline = truck;
   back = NULL;
   while((rd = read(fd, buffer, BUFFER_SIZE)))
   {
      buffer[rd] = 0;
      represent *temp;
      temp = (represent *)malloc(sizeof(represent));
      temp->byteofline = buffer;
      temp->next = NULL;
      if(findnl(buffer, '\n'))
      {
         
      }
   }
   return (list);
}

char    *get_next_line(int fd)
{
    static char *truck = "";
    char        *string;
    char        *oneline;
    represent   *list;
    
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
   list = create_buff_list(fd, (truck == NULL) ? "" : truck);
   string = get_string(list);
   oneline = line_by_line(string);
   truck = findnl(string, '\n');
   printf("hello");
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