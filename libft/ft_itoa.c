/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:59:40 by klee              #+#    #+#             */
/*   Updated: 2017/11/18 12:20:36 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len_nbr(unsigned int nbr)
{
	int		i;

	i = 0;
	while (nbr / 10 != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int nbr)
{
	char			*res;
	unsigned int	r;
	int				d;
	int				i;

	d = (nbr < 0) ? 1 : 0;
	r = (nbr < 0) ? -nbr : nbr;
	i = len_nbr(r) + d;
	res = (char*)ft_memalloc(i + 2);
	if (!res)
		return (0);
	if (d == 1)
		res[0] = '-';
	res[i + 1] = '\0';
	while (i >= d)
	{
		res[i--] = r % 10 + '0';
		r = r / 10;
	}
	return (res);
}
