/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:23:46 by klee              #+#    #+#             */
/*   Updated: 2017/11/20 11:13:31 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	char	*s11;
	char	*s22;

	if (!s1 || !s2)
		return (0);
	s11 = ft_strdup(s1);
	s22 = ft_strdup(s2);
	if (ft_strcmp(s11, s22) != 0)
		return (0);
	return (1);
}
