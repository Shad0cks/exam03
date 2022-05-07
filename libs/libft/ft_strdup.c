/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangoni <arangoni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:29:59 by arangoni          #+#    #+#             */
/*   Updated: 2022/02/24 18:14:39 by arangoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*c;

	if (!src || !*src)
	{
		c = (char *)malloc(1);
		if (c == NULL)
			return (NULL);
		ft_bzero(c, 1);
		return (c);
	}
	c = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	i = -1;
	while (src[++i] != '\0')
		c[i] = src[i];
	c[i] = '\0';
	return (c);
}
