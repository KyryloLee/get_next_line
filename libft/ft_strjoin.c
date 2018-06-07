/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:14:52 by klee              #+#    #+#             */
/*   Updated: 2017/11/20 11:37:34 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	i;
	char			*str;

	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	i = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if (!i)
		return (0);
	str = ft_strnew(i + 1);
	if (!str)
		return (0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
