/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangoni <arangoni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:53:13 by arangoni          #+#    #+#             */
/*   Updated: 2022/04/26 19:37:28 by arangoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlower(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
		if ((str[i] <= 'Z') && (str[i] >= 'A'))
			str[i] += 32;
	return (str);
}
