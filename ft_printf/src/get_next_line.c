/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:42:44 by lhaired           #+#    #+#             */
/*   Updated: 2019/10/23 20:53:30 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoinf(char const *s1, char const *s2)
{
	char *result;

	result = ft_strjoin(s1, s2);
	if (result)
		free((char *)s1);
	return (result);
}

static int	store_rest(char *str, char **rest)
{
	char *tmp;

	if (*str)
	{
		tmp = *rest;
		*rest = ft_strdup(str);
		free(tmp);
	}
	return (1);
}

static int	use_rest(char **line, char **rest, char **end_line)
{
	if (*rest && **rest)
	{
		if ((*end_line = ft_strchr(*rest, '\n')))
		{
			**end_line = '\0';
			if ((store_rest(*rest, line)) == 0)
				return (-1);
			*end_line += 1;
			if (**end_line != '\0')
				store_rest(*end_line, rest);
			else
				ft_strclr(*rest);
			return (1);
		}
		else
		{
			if ((store_rest(*rest, line)) == 0)
				return (-1);
			ft_strclr(*rest);
		}
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*rest[1024];
	char		*end_line;
	int			fread;
	int			fl;

	if (fd < 0 || line == NULL || (*line = ft_strnew(0)) == 0 || fd > 1024)
		return (-1);
	if ((fl = use_rest(line, &rest[fd], &end_line)) != 0)
		return (fl);
	while ((fread = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[fread] = '\0';
		if ((end_line = ft_strchr(buf, '\n')))
		{
			*end_line = '\0';
			store_rest(++end_line, &rest[fd]);
			return (((*line = ft_strjoinf(*line, buf)) == NULL) ? -1 : 1);
		}
		if ((*line = ft_strjoinf(*line, buf)) == NULL)
			return (-1);
	}
	return ((**line && fread == 0) ? 1 : fread);
}
