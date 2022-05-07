/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangoni <arangoni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:49:38 by arangoni          #+#    #+#             */
/*   Updated: 2022/03/03 13:51:54 by arangoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcountc(char *str, char c)
{
	int	n;

	if (!str)
		return (-1);
	n = 0;
	while (*str)
		if (*(str++) == c)
			n++;
	return (n);
}
