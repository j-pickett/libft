/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:13:16 by apickett          #+#    #+#             */
/*   Updated: 2018/04/19 20:27:29 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	unsigned int i;
	unsigned int j;
	unsigned int result;

	i = 0;
	while (dest[i] != '\0')
		++i;
	result = 0;
	while (src[result] != '\0')
		++result;
	if (len <= i)
		result = result + len;
	else
		result = result + i;
	j = 0;
	while (src[j] != '\0' && i + 1 < len)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (result);
}
