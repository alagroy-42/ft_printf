/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:04:07 by alagroy-          #+#    #+#             */
/*   Updated: 2018/12/18 19:09:55 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <float.h>

int	main(void)
{
	char	*test;

	test = ft_strdup("int");
	ft_printf("test # : %#x\n%#X\n%p\n", 546354, 3435435, test);
	return (0);
}
