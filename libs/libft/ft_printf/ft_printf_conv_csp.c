/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_csp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangoni <arangoni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:21:26 by arangoni          #+#    #+#             */
/*   Updated: 2022/02/06 15:39:16 by arangoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	conv_c(void *arg, int flags[7])
{
	int		i;
	char	c;
	char	a;

	c = ' ';
	i = -1;
	while (++i < flags[4])
		write(1, &c, 1);
	a = (intptr_t)arg;
	write(1, &a, 1);
	while (++i < (int)ft_abs(flags[4]) && flags[4] < 0)
		write(1, &c, 1);
	if (ft_abs(flags[4]))
		return (ft_abs(flags[4]));
	return (1);
}

int	conv_s(void *arg, int flags[7])
{
	char	*s;
	int		len_s;

	if (!arg)
		s = ft_substr("(null)", 0, flags[5]);
	else
		s = ft_substr(arg, 0, flags[5]);
	if (!s)
		return (-1);
	s = min_field(s, flags[4], flags[3]);
	if (!s)
		return (-1);
	ft_putstr_fd(s, 1);
	len_s = ft_strlen(s);
	free(s);
	return (len_s);
}

int	conv_p(void *arg, int flags[7])
{
	int					len_s;
	char				*s;
	char				*t;
	unsigned const char	hex[17] = "0123456789abcdef";

	s = to_base((unsigned long long)arg, (const char *)hex);
	len_s = ft_strlen(s);
	t = precision(s, flags);
	if (!s || !t)
		return (-1);
	if (flags[3] && flags[4] > 2)
		t = min_field(t, flags[4] - 2, flags[3]);
	free(s);
	s = ft_strjoin("0x", t);
	if (!s || !t)
		return (-1);
	if (!flags[3] || flags[4] < 0)
		s = min_field(s, flags[4], flags[3]);
	if (!s)
		return (-1);
	ft_putstr_fd(s, 1);
	len_s = ft_strlen(s);
	free(t);
	free(s);
	return (len_s);
}
