/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:01:37 by alagroy-          #+#    #+#             */
/*   Updated: 2018/12/18 19:38:40 by alagroy-         ###   ########.fr       */
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

t_flags	ft_space(t_flags space)
{
	if (ft_strchr("dif", rtrn.type) && rtrn.content != '-')
		rtrn.content = ft_strjoin(" ", rtrn.content);
	return (rtrn);
}
