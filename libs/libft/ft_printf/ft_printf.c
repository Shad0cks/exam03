/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arangoni <arangoni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:45:46 by arangoni          #+#    #+#             */
/*   Updated: 2022/02/03 02:43:34 by arangoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	f_constr(int (*f[9])(void *, int[7]))
{
	f[0] = &conv_c;
	f[1] = &conv_s;
	f[2] = &conv_p;
	f[3] = &conv_d;
	f[4] = &conv_i;
	f[5] = &conv_u;
	f[6] = &conv_x;
	f[7] = &conv_big_x;
	f[8] = &conv_prct;
}

static char	*flags(char *s, int flags_tab[7])
{
	const char	flags_set[5] = " +#0";
	int			i;

	i = -1;
	while (++i < 7)
		flags_tab[i] = 0;
	while (ft_strchr(flags_set, *s) && *s)
		flags_tab[ft_strchr(flags_set, *(s++)) - flags_set] = 1;
	flags_tab[4] = mini_atoi(&s);
	flags_tab[5] = -1;
	if (*s == '.')
	{
		s++;
		flags_tab[5] = mini_atoi(&s);
		if (flags_tab[5] < 0)
			flags_tab[5] = -1;
	}
	flags_tab[6] = *s;
	return (s);
}

static int	conv(int flags_tab[7], va_list *arg_lst)
{
	int			(*f[9])(void *, int [7]);
	char		*s;
	const char	conv_set[10] = "cspdiuxX%";

	f_constr(f);
	s = ft_strchr(conv_set, flags_tab[6]);
	if (!s)
		return (f[0]((void *)(size_t)flags_tab[6], flags_tab));
	if (*s == '%')
		return (f [s - conv_set](0, flags_tab));
	return (f[s - conv_set](va_arg(*arg_lst, void *), flags_tab));
}

int	ft_printf(const char *s, ...)
{
	va_list		arg_lst;
	int			printed_size;
	int			flags_tab[7];
	char		*t;

	va_start(arg_lst, s);
	printed_size = 0;
	t = (char *)s;
	while (*t)
	{
		if (*t == '%' && *(t + 1))
		{
			t = flags(++t, flags_tab);
			if (!flags_tab[6] && !*t)
				return (printed_size);
			printed_size += conv(flags_tab, &arg_lst);
		}
		else if (*t != '%')
			printed_size += write(1, t, 1);
		t++;
	}
	va_end(arg_lst);
	return (printed_size);
}
