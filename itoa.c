/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:24:16 by alagroy-          #+#    #+#             */
/*   Updated: 2018/12/20 19:27:00 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "ft_printf.h"
#include "libft.h"

char	*ft_itoa_max(long double nb)
{
	int			nb_digit;
	intmax_t	tmp;
	int			neg;
	char		*rtrn;

	neg = (nb < 0) ? 1 : 0;
	tmp = nb;
	nb_digit = 1;
	while (tmp /= 10)
		nb_digit++;
	nb_digit += neg;
	if (!(rtrn = (char *)malloc((nb_digit + 1) * sizeof(char))))
		return (NULL);
	rtrn[nb_digit] = '\0';
	if (neg)
		rtrn[0] = '-';
	if (neg)
		nb *= -1;
	while (--nb_digit >= neg)
	{
		rtrn[nb_digit] = nb % 10 + '0';
		nb /= 10;
	}
	return (rtrn);
}

char	*ft_itoa_base(intmax_t nb, int base)
{
	int			nb_digit;
	intmax_t	tmp;
	int			neg;
	char		*rtrn;

	neg = (nb < 0) ? 1 : 0;
	tmp = nb;
	nb_digit = 1;
	while (tmp /= base)
		nb_digit++;
	nb_digit += neg;
	if (!(rtrn = (char *)malloc((nb_digit + 1) * sizeof(char))))
		return (NULL);
	rtrn[nb_digit] = '\0';
	if (neg)
		rtrn[0] = '-';
	if (neg)
		nb *= -1;
	while (--nb_digit >= neg)
	{
		rtrn[nb_digit] = (nb % base < 10) ? nb % base + '0' :
			nb % base + 'A' - 10;
		nb /= base;
	}
	return (rtrn);
}

char	*ft_itoa_base_lowcase(intmax_t nb, int base)
{
	int			nb_digit;
	intmax_t	tmp;
	int			neg;
	char		*rtrn;

	neg = (nb < 0) ? 1 : 0;
	tmp = nb;
	nb_digit = 1;
	while (tmp /= base)
		nb_digit++;
	nb_digit += neg;
	if (!(rtrn = (char *)malloc((nb_digit + 1) * sizeof(char))))
		return (NULL);
	rtrn[nb_digit] = '\0';
	if (neg)
		rtrn[0] = '-';
	if (neg)
		nb *= -1;
	while (--nb_digit >= neg)
	{
		rtrn[nb_digit] = (nb % base < 10) ? nb % base + '0' :
			nb % base + 'a' - 10;
		nb /= base;
	}
	return (rtrn);
}

char	*ft_itoa_float(long double nb, t_flags rtrn)
{
	char		*ret;
	long double	tmp;

	tmp = nb * ft_power(10, rtrn.size_float);
	if (tmp - (int)tmp >= 0.5)
		tmp++;
	ret = ft_itoa_max(tmp);	
	ret = ft_insert_str(ret, ft_strdup("."), ft_strlen(ret) - rtrn.size_float);
	return (ret);
}
