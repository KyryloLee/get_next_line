/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:56:29 by klee              #+#    #+#             */
/*   Updated: 2017/11/20 11:14:48 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	char	*s11;
	char	*s22;

	if (!s1 || !s2)
		return (0);
	s11 = ft_strdup(s1);
	s22 = ft_strdup(s2);
	if (ft_strncmp(s11, s22, n) != 0)
		return (0);
	return (1);
}
