/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:13:18 by alagroy-          #+#    #+#             */
/*   Updated: 2018/12/18 19:38:42 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*rtrn;
	int		i;

	i = -1;
	if (!(rtrn = ft_strdup(format)))
		return (-1);
	va_start(ap, format);
	while (rtrn[++i])
		if (rtrn[i] == '%')
			rtrn = ft_fill_format(rtrn, rtrn + i, ap);
	ft_putendl(rtrn);
	va_end(ap);
	return (ft_strlen(rtrn));
}

char	*ft_fill_format(char *copy, char *flags, va_list ap)
{
	char	*rtrn;
	int		index;
	t_flags current;

	index = flags - copy;
	current = ft_init_flags();
	if (flags[1] && flags[1] == '%')
		rtrn = ft_double_percent(copy, flags);
	else
		current = ft_fill_struct(flags, ap);
	if (current.content == NULL)	
		rtrn = ft_double_percent(copy, flags);
	else
	{	
		current = ft_find_nb_char(current);
		rtrn = ft_delete_flags(copy, index, current.nb_char);
		rtrn = ft_insert_str(rtrn, current.content, index);
	}
	return (rtrn);
}

t_flags	ft_fill_struct(char *flags, va_list ap)
{
	int		i;
	t_flags	rtrn;

	i = 0;
	rtrn = ft_init_flags();
	while (flags[++i] && ft_isoption(flags[i]))
	{
		rtrn.hashtag = (flags[i] == '#' || rtrn.hashtag) ? 1 : 0;
		rtrn.space = (flags[i] == ' ' || rtrn.space) ? 1 : 0;
		rtrn.plus = (flags[i] == '+' || rtrn.plus) ? 1 : 0;
		rtrn.minus = (flags[i] == '-' || rtrn.minus) ? 1 : 0;
		rtrn.zero = (flags[i] == '0' || rtrn.zero) ? 1 : 0;
	}
	if (flags[i - 1] != '.')
		rtrn.min_size = ft_atoi(flags + i);
	else
		rtrn.size_float = ft_atoi(flags + i);
	rtrn = ft_fill_convert(flags + i, rtrn);
	rtrn = ft_fill_type(flags + i, rtrn);
	rtrn = ft_fill_content(rtrn, ap);
	return (rtrn);
}

t_flags	ft_fill_convert(char *convert, t_flags rtrn)
{	
	while (ft_isdigit(convert[0]))
		convert++;
	rtrn.convert = (convert[0] == 'h' && ft_strncmp(convert, "hh", 2)) ? h
		: rtrn.convert;
	rtrn.convert = (!ft_strncmp(convert, "hh", 2) && rtrn.convert == none) ? hh
		: rtrn.convert;
	rtrn.convert = (convert[0] == 'l' && rtrn.convert == none
			&& ft_strncmp(convert, "ll", 2)) ? l : rtrn.convert;
	rtrn.convert = (convert[0] == 'L' && rtrn.convert == none) ? L
		: rtrn.convert;
	rtrn.convert = (!ft_strncmp(convert, "ll", 2) && rtrn.convert == none) ? ll
		: rtrn.convert;
	return (rtrn);
}

t_flags	ft_fill_type(char *flags, t_flags rtrn)
{
	int	i;

	i = 0;
	while (ft_isdigit(flags[i]) || ft_strchr("hlL", flags[i]))
		i++;
	if (ft_strchr("diouxXcspf", flags[i]))
		rtrn.type = flags[i];
	return (rtrn);
}
