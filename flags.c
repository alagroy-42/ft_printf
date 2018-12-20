/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:01:37 by alagroy-          #+#    #+#             */
/*   Updated: 2018/12/20 16:13:20 by alagroy-         ###   ########.fr       */
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

	i = -1;
	if (rtrn.min_size <= (int)ft_strlen(rtrn.content))
		return (rtrn);
	min_size = ft_strnew(rtrn.min_size - ft_strlen(rtrn.content));
	while (min_size[++i])
		min_size[i] = ' ';
	rtrn.content = ft_strjoin(rtrn.content, min_size);
	return (rtrn);
}

t_flags	ft_zero_min_size(t_flags rtrn)
{
	int		i;
	char	*min_size;
	int		size;
// modifier avec size parce que strnew ne mets que des '\0'
	size = 
	i = -1;
	if (rtrn.min_size <= (int)ft_strlen(rtrn.content))
		return (rtrn);
	min_size = ft_strnew(rtrn.min_size - ft_strlen(rtrn.content));
	while ()
		min_size[i] = rtrn.zero ? '0' : ' ';
	rtrn.content = ft_strjoin(min_size, rtrn.content);
	return (rtrn);
}
