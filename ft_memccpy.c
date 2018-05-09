/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apickett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:29:17 by apickett          #+#    #+#             */
/*   Updated: 2018/04/30 20:09:07 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*db;
	unsigned char	*sb;

	i = 0;
	db = (unsigned char *)dest;
	sb = (unsigned char *)src;
	while (n--)
	{
		*(db++) = *(sb);
		if (*sb == (unsigned char)c)
			return (db);
		sb++;
	}
	return (NULL);
}
