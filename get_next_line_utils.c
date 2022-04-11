/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:22:28 by dmartiro          #+#    #+#             */
/*   Updated: 2022/04/04 19:22:30 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
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