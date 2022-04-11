/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:21:53 by dmartiro          #+#    #+#             */
/*   Updated: 2022/04/11 04:57:35 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char    *slashn(char *buffer, char n)
{
    //stugum enq qani der chka toxi verjy
    while(*buffer++)
    {
        if(*buffer == n)
            return ((char *)buffer);
    }
    if(*buffer == n)
        return ((char *)buffer);
    return (0);
}


char    *get_next_line(int fd)
{
    static char *truck;
    char        *buffer;
    represent   *node;
    int         rd;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
    node = (represent *)malloc(sizeof(represent));
    node->prev = NULL;
    node->byteofline = truck;
    return (truck);
}

int main(void)
{
   int fd = open("file.txt", O_RDONLY);
   get_next_line(fd);
}



// static char *get_line(represent *list, char *truck, char *(rest)(represent))
// {
//     // rest funkcian ktruma \n-ic heto mnacac masy ev dnum truck popxakani mej
//     //talis enq listy stexcuma string u veradardznuma stringy
//     //kanchum enq freen 
// }
// static char *rest(represent *lastnode, char *truck)
// {
//     //funkcia vory kvercni listi verjin node u kktri ayn 
//     //ev kdni truck popoxakani mej vory im static popxakann e
// }