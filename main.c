/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:04:07 by alagroy-          #+#    #+#             */
/*   Updated: 2018/12/20 17:59:33 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>

int	main(void)
{
	char	*test;

	test = strdup("test .2");
	ft_printf("test .2 : %-24.2f\n", 1.34333333135);
	return (0);
}
