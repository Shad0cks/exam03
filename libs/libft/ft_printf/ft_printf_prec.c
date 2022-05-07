/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangoni <arangoni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:30:51 by arangoni          #+#    #+#             */
/*   Updated: 2022/02/03 02:43:26 by arangoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*precision(char *s, int flags[7])
{
	char	*t;
	int		len_s;

	len_s = ft_strlen(s);
	if (flags[5] > len_s)
	{
		t = ft_calloc(flags[5] - len_s + 1, 1);
		if (t)
			ft_memset(t, '0', flags[5] - len_s);
		t = ft_freejoin(t, s);
	}
	else
		t = ft_strdup(s);
	return (t);
}
