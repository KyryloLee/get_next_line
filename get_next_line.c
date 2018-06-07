/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:27:54 by klee              #+#    #+#             */
/*   Updated: 2017/12/19 15:34:38 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "stdio.h"

char	*fk_strjoin(char *s1, char *s2)
{
	char	*fresh;
	int		l1;
	int		l2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	fresh = (char*)malloc(sizeof(char) * (l1 + l2 + 1));
	if (fresh == 0)
		return (NULL);
	l1 = 0;
	l2 = 0;
	while (s1[l1] && (fresh[l1] = s1[l1]))
		l1++;
	while (s2[l2] && (fresh[l1++] = s2[l2++]))
		;
	fresh[l1] = '\0';
	return (fresh);
}

char	*fk_strdup(const char *s1)
{
	int		l;
	int		i;
	char	*s2;

	i = 0;
	l = 0;
	while (s1[l])
		l++;
	s2 = (char*)malloc(sizeof(char) * (l + 1));
	if (s2 == 0)
		return (0);
	while (i < l)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

t_list	*correct_list(t_list **plus_str, int fd)
{
	t_list	*tmp;

	tmp = *plus_str;
	if (*plus_str == NULL)
	{
		ft_lstadd(plus_str, ft_lstnew("", fd));
		tmp = *plus_str;
	}
	else
	{
		while (tmp)
			if (tmp->content_size != (size_t)fd)
				tmp = tmp->next;
			else
				return (tmp);
		ft_lstadd(plus_str, ft_lstnew("", fd));
		tmp = *plus_str;
	}
	return (tmp);
}

int		read_file(char **tmlls, int fd)
{
	char				buf[BUFF_SIZE + 1];
	char				*str;
	int					ret;

	ret = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		str = *tmlls;
		*tmlls = fk_strjoin(*tmlls, buf);
		free(str);
		if (ft_strchr(*tmlls, '\n'))
			break ;
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static t_list		*plus_str = NULL;
	t_list				*tmp;
	int					ret;
	char				*tmlls;
	int					count;

	count = 0;
	if (!line || (read(fd, "", 0) < 0))
		return (-1);
	tmp = correct_list(&plus_str, fd);
	tmlls = !tmp->content ? ft_strnew(1) : tmp->content;
	ret = read_file(&tmlls, fd);
	if (ret == 0 && !ft_strlen(tmlls))
	{
		*line = ft_strnew(1);
		return (0);
	}
	count = ft_strchr(tmlls, '\n') ?
		(ft_strchr(tmlls, '\n') - tmlls) : ft_strlen(tmlls);
	tmp->content = ft_strchr(tmlls, '\n') ?
		fk_strdup(ft_strchr(tmlls, '\n') + 1) : 0;
	*line = ft_strsub(tmlls, 0, count);
	free(tmlls);
	return (1);
}
