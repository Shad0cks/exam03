/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangoni <arangoni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:19:15 by arangoni          #+#    #+#             */
/*   Updated: 2022/02/03 02:43:11 by arangoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	mini_atoi(char **s)
{
	long int	n;
	int			m;

	m = 1;
	n = 0;
	if (**s == '-')
	{
		m *= -1;
		(*s)++;
	}
	while (ft_isdigit(**s))
		n = n * 10 + (*(*s)++ - '0');
	return (n * m);
}

char	*min_field(char *s, int field, int field_type)
{
	int		len_s;
	char	c;
	char	*t;

	len_s = ft_strlen(s);
	if (len_s >= (int)ft_abs(field))
		return (s);
	c = ' ';
	if (field_type && field > 0)
		c = '0';
	t = ft_calloc(1, ft_abs(field) - len_s + 1);
	ft_memset(t, c, ft_abs(field) - len_s);
	if (field > 0)
	{
		t = ft_freejoin(t, s);
		free(s);
		return (t);
	}
	s = ft_freejoin(s, t);
	free(t);
	return (s);
}

char	*to_base(unsigned long long n, const char *base)
{
	int					len_n;
	int					len_base;
	char				*s;
	unsigned long long	i;

	i = n;
	len_n = 0;
	len_base = ft_strlen(base);
	while (i > 0)
	{
		len_n++;
		i /= len_base;
	}
	s = (char *)ft_calloc(len_n + 1 + (len_n == 0), 1);
	if (!s)
		return (0);
	i = n;
	if (len_n == 0)
		s[0] = base[0];
	while (len_n--)
	{
		s[len_n] = base[i % len_base];
		i /= len_base;
	}
	return (s);
}
