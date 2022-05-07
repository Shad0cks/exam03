/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangoni <arangoni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:38:01 by arangoni          #+#    #+#             */
/*   Updated: 2022/02/04 00:38:07 by arangoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*gc_add(t_list **gc, size_t size)
{
	void	*data;
	t_list	*node;

	data = malloc(size);
	node = ft_lstnew(data);
	if (!node)
		free(data);
	if (!data)
		ft_lstdelone(node, free);
	if (!node || !data)
	{	
		ft_lstclear(gc, free);
		exit(EXIT_FAILURE);
	}
	ft_lstadd_back(gc, node);
	return (data);
}
