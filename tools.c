/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:28:19 by alagroy-          #+#    #+#             */
/*   Updated: 2018/12/20 14:45:38 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_flags	ft_init_flags(void)
{
	t_flags	rtrn;

	rtrn.hashtag = 0;
	rtrn.space = 0;
	rtrn.plus = 0;
	rtrn.minus = 0;
	rtrn.zero = 0;
	rtrn.min_size = 0;
	rtrn.size_float = 6;
	rtrn.size_float_status = 0;
	rtrn.convert = none;
	rtrn.type = '\0';
	rtrn.nb_char = 0;
	rtrn.content = NULL;
	return (rtrn);
}

int		ft_power(int nb, int pow)
{
	int ret;
	
	ret = nb;
	if (pow)
	while (--pow > 0)
		ret *= nb;
	return (ret);
}

int		ft_isoption(char c)
{
	if (c == '#' || c == '+' || c == '-' || c == ' ' || c == '0')
		return (1);
	return (0);
}
