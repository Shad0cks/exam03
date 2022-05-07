/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_iud.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangoni <arangoni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:23:06 by arangoni          #+#    #+#             */
/*   Updated: 2022/02/06 15:55:46 by arangoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*prefix_n(long int arg, int flags[7])
{
	if (arg < 0)
		return (ft_strdup("-"));
	else if (flags[1])
		return (ft_strdup("+"));
	else if (flags[0])
		return (ft_strdup(" "));
	return (ft_strdup(""));
}

int	conv_d(void *arg, int flags[7])
{
	int					len_s;
	char				*prefix;
	char				*s;
	char				*t;
	unsigned const char	dec[17] = "0123456789";

	s = to_base((unsigned long long)ft_abs((intptr_t)arg), (const char *)dec);
	t = precision(s, flags);
	prefix = prefix_n((int)(intptr_t)arg, flags);
	if ((unsigned long)flags[4] > ft_strlen(t) + ft_strlen(prefix) && flags[3])
		t = min_field(t, flags[4] - ft_strlen(prefix), flags[3]);
	free(s);
	s = ft_freejoin(prefix, t);
	free(t);
	if (ft_abs(flags[4]) > (int)ft_strlen(s))
		s = min_field(s, flags[4], flags[3]);
	if (!s)
		return (-1);
	ft_putstr_fd(s, 1);
	len_s = ft_strlen(s);
	free(s);
	return (len_s);
}

int	conv_i(void *arg, int flags[7])
{
	return (conv_d(arg, flags));
}

int	conv_u(void *arg, int flags[7])
{
	int					len_s;
	char				*prefix;
	char				*s;
	char				*t;
	unsigned const char	dec[17] = "0123456789";

	s = to_base((unsigned long long)arg, (const char *)dec);
	len_s = ft_strlen(s);
	t = precision(s, flags);
	prefix = prefix_n((uintptr_t)arg, flags);
	if ((unsigned long)flags[4] > ft_strlen(t) + ft_strlen(prefix) && flags[3])
		t = min_field(t, flags[4] - ft_strlen(prefix), flags[3]);
	free(s);
	s = ft_freejoin(prefix, t);
	free(t);
	if (ft_abs(flags[4]) > (int)ft_strlen(s))
		s = min_field(s, flags[4], flags[3]);
	if (!s)
		return (-1);
	ft_putstr_fd(s, 1);
	len_s = ft_strlen(s);
	free(s);
	return (len_s);
}
