/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelache <abelache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:00:52 by arangoni          #+#    #+#             */
/*   Updated: 2022/03/03 16:11:58 by abelache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**error_tab(char **tab_copy, char **tab, int free_tab)
{
	if (tab && free_tab)
		ft_freetab(tab);
	ft_freetab(tab_copy);
	return (NULL);
}

static char	**fill_copy(char **tab, char **tab_copy, int pos)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (i < pos)
			tab_copy[i] = ft_strdup(tab[i]);
		else if (i >= pos)
			tab_copy[i + 1] = ft_strdup(tab[i]);
		if ((!tab_copy[i] && i <= pos) || (!tab_copy[i + 1] && i > pos))
			return (NULL);
	}
	return (tab_copy);
}

char	**ft_tab_add(char **tab, char *new, int pos, int free_tab)
{
	char	**tab_copy;

	if (!tab || !new)
		return (NULL);
	tab_copy = (char **)ft_calloc(ft_tab_size(tab) + 2, sizeof(char *));
	if (!tab_copy)
		return (NULL);
	if (pos >= 0)
		tab_copy[pos] = ft_strdup(new);
	if (!fill_copy(tab, tab_copy, pos))
		return (error_tab(tab_copy, tab, free_tab));
	if (pos < 0)
	{
		tab_copy[ft_tab_size(tab_copy)] = ft_strdup(new);
		if (!tab_copy[ft_tab_size(tab) + 1])
			return (error_tab(tab_copy, tab, free_tab));
	}
	if (free_tab)
		ft_freetab(tab);
	tab_copy[ft_tab_size(tab_copy)] = NULL;
	return (tab_copy);
}
