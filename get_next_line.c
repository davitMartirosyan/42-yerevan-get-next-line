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

char  *line_by_line(char *string)
{

}

represent   *create_buff_list(int fd, char *truck)
{

}

char    *get_next_line(int fd)
{
   static char *truck = "";
   struct represent  *list;
   char        *string;
   char        *oneline;

   list = create_buff_list(fd, truck);
   string = get_string(list);
   oneline = line_by_line(string);
   truck = findnl(string, '\n');
   free(string);
   return (oneline);
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
    
    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    list = create_buff_list(fd, truck);
    string = get_string(list);
    oneline = line_by_line(string);
    truck = findnl(string, '\n');
    return (oneline);
    */