/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:51:46 by alagroy-          #+#    #+#             */
/*   Updated: 2018/12/18 19:38:44 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h> //a enlever
t_flags	ft_fill_content(t_flags rtrn, va_list ap)
{
	intmax_t arg;

	if (ft_strchr("ouxX", rtrn.type))
	{
		if (rtrn.convert == h)
			arg = (unsigned short int)va_arg(ap, unsigned int);
		else if (rtrn.convert == hh)
			arg = (unsigned char)va_arg(ap, int);
		else if (rtrn.convert == l)
			arg = va_arg(ap, unsigned long);
		else if (rtrn.convert == ll)
			arg = (unsigned long long int)va_arg(ap, unsigned long long int);
		else
			arg = (unsigned int)va_arg(ap, unsigned int);
		if (rtrn.type == 'o')
			rtrn.content = ft_itoa_base(arg, 8);
		else if (rtrn.type == 'u')
			rtrn.content = ft_itoa_max(arg);
		else if (rtrn.type == 'x')
			rtrn.content = ft_itoa_base_lowcase(arg, 16);
		else if (rtrn.type == 'X')
			rtrn.content = ft_itoa_base(arg, 16);
	}
	else
		rtrn = ft_fill_content2(rtrn, ap);
	rtrn = ft_fill_options(rtrn);
	return (rtrn);
}

t_flags	ft_fill_content2(t_flags rtrn, va_list ap)
{
	intmax_t arg;

	if (ft_strchr("di", rtrn.type))
	{
		if (rtrn.convert == h)
			arg = (short int)va_arg(ap, int);
		else if (rtrn.convert == hh)
			arg = (signed char)va_arg(ap, int);
		else if (rtrn.convert == l)
			arg = va_arg(ap, long int);
		else if (rtrn.convert == ll)
			arg = va_arg(ap, long long int);
		else
			arg = va_arg(ap, int);
		rtrn.content = ft_itoa_max(arg);
	}
	else
		rtrn = ft_fill_content3(rtrn, ap);
	return (rtrn);
}

t_flags	ft_fill_content3(t_flags rtrn, va_list ap)
{
	char 		argc;
	char		*args;
	long		argp;
	long double	argf;

	if (ft_strchr("csp", rtrn.type))
	{
		if (rtrn.type == 'c')
			argc = (char)va_arg(ap, int);
		else if (rtrn.type == 's')
			args = va_arg(ap, char *);
		else if (rtrn.type == 'p')
			argp = va_arg(ap, long);
		if (rtrn.type == 'c')
			rtrn.content = ft_strdup(&argc);
		else if (rtrn.type == 's')
			rtrn.content = ft_strdup(args);
		else if (rtrn.type == 'p')
			rtrn.content = ft_strjoin("0x", ft_itoa_base(argp, 16));
	}
	else if (rtrn.type == 'f')
	{
		if (rtrn.convert == none)
			argf = va_arg(ap, double);
		else if (rtrn.convert == l)
			argf = va_arg(ap, double);
		else
			argf = va_arg(ap, long double);
		rtrn.content = ft_itoa_float(argf, rtrn);
	}
	return (rtrn);
}

t_flags	ft_find_nb_char(t_flags rtrn)
{
	int		nb_char;
	char	*numbers;

	nb_char = 1;
	nb_char += rtrn.hashtag;
	nb_char += rtrn.space;
	nb_char += rtrn.plus;
	nb_char += rtrn.minus;
	nb_char += rtrn.zero;
	numbers = ft_itoa(rtrn.min_size);
	nb_char += (numbers[0] == '0') ? 0 : ft_strlen(numbers);
	nb_char += (rtrn.type) ? 1 : 0;
	numbers = ft_itoa(rtrn.size_float);
	nb_char += (numbers[0] == '6') ? 0 : ft_strlen(numbers);
	nb_char += (rtrn.convert == h) ? 1 : 0;
	nb_char += (rtrn.convert == hh) ? 2 : 0;
	nb_char += (rtrn.convert == l) ? 1 : 0;
	(rtrn.convert == ll) ? nb_char += 2 : 0;
	nb_char += (rtrn.convert == L) ? 1 : 0;
	rtrn.nb_char = nb_char;
	return (rtrn);
}

t_flags	ft_fill_options(t_flags rtrn)
{
	if (rtrn.hashtag)
		rtrn = ft_hashtag(rtrn);
	return (rtrn);
}
