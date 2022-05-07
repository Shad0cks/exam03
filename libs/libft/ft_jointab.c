/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jointab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelache <abelache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:34:59 by arangoni          #+#    #+#             */
/*   Updated: 2022/03/03 14:39:15 by abelache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_jointab(char **tab, char c)
{
	char	*joined;

	if (!tab)
		return (NULL);
	joined = ft_strdup("");
	if (!joined)
		return (NULL);
	while (*tab)
	{
		joined = ft_freejoin(joined, *tab);
		if (!joined)
			return (NULL);
		tab++;
		if (*tab)
			joined = ft_freejoinchar(joined, c);
	}
	return (joined);
}
