/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:44:57 by amaarifa          #+#    #+#             */
/*   Updated: 2021/11/28 13:27:37 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char **s)
{
	char	*temp;
	int		j;
	char	*t_s;

	j = get_nl(*s);
	if (j >= 0)
	{
		temp = ft_substr(*s, 0, j + 1);
		t_s = ft_strdup(*s + j + 1);
		free(*s);
		*s = t_s;
		return (temp);
	}
	temp = ft_strdup(*s);
	s[0][0] = '\0';
	return (temp);
}

void	read_line(int fd, char **buf, char **s)
{
	int	j;

	while (1)
	{
		j = read(fd, *buf, BUFFER_SIZE);
		if (j <= 0)
			break ;
		buf[0][j] = '\0';
		*s = ft_strjoin(*s, *buf);
		if (get_nl(*buf) >= 0)
			break ;
	}
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*s[1024];

	if (fd < 0 || fd > 1024)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	if (!s[fd])
		s[fd] = ft_strdup("");
	read_line(fd, &buf, &s[fd]);
	free(buf);
	if (s[fd] && s[fd][0])
		return (get_line(&s[fd]));
	if (s[fd])
		free(s[fd]);
	s[fd] = NULL;
	return (0);
}
