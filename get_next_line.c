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
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

represent   *create_buff_list(int fd, char *truck)
{
    represent   *list;
    represent   *addr;
    char        *buffer;
    int         rd;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    list = (represent *)malloc(sizeof(represent));
    list->byteofline = truck;
    addr = list;
    while((rd = read(fd, buffer, BUFFER_SIZE)))
    {
       
    }
    // printf("%s", list->byteofline);
    free(buffer);
    return (list);
}

char    *get_next_line(int fd)
{
   static char  *truck = "";
   represent *list = create_buff_list(fd, truck);
   printf("%s", get_string(list));
   return ("okay");
   
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