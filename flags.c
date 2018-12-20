/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:01:37 by alagroy-          #+#    #+#             */
/*   Updated: 2018/12/20 18:01:02 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_flags	ft_hashtag(t_flags rtrn)
{
	if (rtrn.type == 'x')
		rtrn.content = ft_strjoin("0x", rtrn.content);
	else if (rtrn.type == 'X')
		rtrn.content = ft_strjoin("0X", rtrn.content);
	return (rtrn);
}

t_flags	ft_space(t_flags rtrn)
{
	if (ft_strchr("dif", rtrn.type) && rtrn.content[0] != '-' && !rtrn.plus)
		rtrn.content = ft_strjoin(" ", rtrn.content);
	return (rtrn);
}

t_flags	ft_plus(t_flags rtrn)
{
	if (ft_strchr("dif", rtrn.type) && rtrn.content[0] != '-')
		rtrn.content = ft_strjoin("+", rtrn.content);
	return (rtrn);
}

t_flags	ft_minus(t_flags rtrn)
{
	int		i;
	char	*min_size;
	int		size;
	
	size = rtrn.min_size - ft_strlen(rtrn.content);
	i = -1;
	if (size < 0)
		return (rtrn);
	min_size = ft_strnew(size);
	while (++i < size)
		min_size[i] = ' ';
	rtrn.content = ft_strjoin(rtrn.content, min_size);
	return (rtrn);
}

t_flags	ft_zero_min_size(t_flags rtrn)
{
	int		i;
	char	*min_size;
	int		size;
	
	size = rtrn.min_size - ft_strlen(rtrn.content);
	i = -1;
	if (size < 0)
		return (rtrn);
	min_size = ft_strnew(size);
	while (++i < size)
		min_size[i] = rtrn.zero ? '0' : ' ';
	rtrn.content = ft_strjoin(min_size, rtrn.content);
	return (rtrn);
}
