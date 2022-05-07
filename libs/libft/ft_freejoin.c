/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangoni <arangoni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:38:37 by arangoni          #+#    #+#             */
/*   Updated: 2022/04/26 19:34:57 by arangoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freejoin(char *s1, char const *s2)
{
	char	*t;
	int		i;
	int		len_s1;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	t = (char *)malloc((len_s1 + ft_strlen(s2) + 1) * sizeof(char));
	if (!t)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (++i < len_s1)
		t[i] = s1[i];
	i = -1;
	while (s2[++i])
		t[len_s1 + i] = s2[i];
	t[len_s1 + i] = '\0';
	free(s1);
	return (t);
}

char	*ft_freejoinchar(char *s1, char const s2)
{
	char	*t;
	int		i;
	int		len_s1;

	if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	t = (char *)malloc((len_s1 + 2) * sizeof(char));
	if (!t)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (++i < len_s1)
		t[i] = s1[i];
	i = -1;
	++i;
		t[len_s1 + i] = s2;
	i++;
	t[len_s1 + i] = '\0';
	free(s1);
	return (t);
}
