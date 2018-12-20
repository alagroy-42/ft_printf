/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:31:20 by alagroy-          #+#    #+#             */
/*   Updated: 2018/11/13 18:36:29 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *begin)
{
	size_t	size;

	size = 0;
	while (begin->next)
	{
		size++;
		begin->next = begin->next->next;
	}
	return (size);
}
