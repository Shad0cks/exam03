/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_hex_sharp.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangoni <arangoni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:22:24 by arangoni          #+#    #+#             */
/*   Updated: 2022/02/06 15:38:24 by arangoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*hexa_x(char *s, int flags[7], int x)
{
	char	*t;
	char	*v;

	t = precision(s, flags);
	if (!s || !t)
		return (NULL);
	if (flags[3] && flags[4] > 2)
		t = min_field(t, flags[4] - 2, flags[3]);
	if (!flags[2])
		return (t);
	if (x == 2)
		v = ft_strjoin("0X", t);
	else if (x == 1)
		v = ft_strjoin("0x", t);
	else
		return (t);
	free(t);
	return (v);
}

int	conv_x(void *arg, int flags[7])
{
	int					len_s;
	char				*s;
	char				*t;
	unsigned const char	hex[17] = "0123456789abcdef";

	s = to_base((uintptr_t)arg, (const char *)hex);
	flags[4] += 2;
	if ((uintptr_t)arg == 0)
		flags[2] = 0;
	t = hexa_x(s, flags, flags[2]);
	free(s);
	if (!s || !t)
		return (-1);
	if (!flags[3] || flags[4] < 2)
		t = min_field(t, flags[4] - 2, flags[3]);
	if (!t)
		return (-1);
	ft_putstr_fd(t, 1);
	len_s = ft_strlen(t);
	free(t);
	return (len_s);
}

int	conv_big_x(void *arg, int flags[7])
{
	int					len_s;
	char				*s;
	char				*t;
	unsigned const char	hex[17] = "0123456789ABCDEF";

	s = to_base((uintptr_t)arg, (const char *)hex);
	flags[4] += 2;
	flags[2] *= 2;
	if ((uintptr_t)arg == 0)
		flags[2] = 0;
	t = hexa_x(s, flags, flags[2]);
	free(s);
	if (!s || !t)
		return (-1);
	if (!flags[3] || flags[4] < 2)
		t = min_field(t, flags[4] - 2, flags[3]);
	if (!t)
		return (-1);
	ft_putstr_fd(t, 1);
	len_s = ft_strlen(t);
	free(t);
	return (len_s);
}

int	conv_prct(void *arg, int flags[7])
{
	int		i;
	char	c;
	char	a;

	(void)arg;
	c = ' ';
	i = -1;
	while (++i < flags[4])
		write(1, &c, 1);
	a = '%';
	write(1, &a, 1);
	while (++i < (int)ft_abs(flags[4]) && flags[4] < 0)
		write(1, &c, 1);
	if (ft_abs(flags[4]))
		return (ft_abs(flags[4]));
	return (1);
}
