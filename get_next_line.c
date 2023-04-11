/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:40:39 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/11 00:25:00 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	search(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*join(char *s, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
	if (!s)
	{
		s = malloc(1);
		s[0] = '\0';
	}
	if (!buffer)
		return (NULL);
	str = malloc (sizeof(char) * ((ft_strlen(s) + ft_strlen(buffer)) + 1));
	if (!str)
		return (NULL);
	while (s[++i] != '\0')
			str[i] = s[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[i] = '\0';
	free(s);
	return (str);
}

// size_t	ft_strlen(char *s)
// {
// 	size_t	i;

// 	if (!s)
// 		return (0);
// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }
char	*reading(int fd, char *s)
{
	char	*buffer;
	int		n;

	n = 1;
	buffer = malloc (sizeof (char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!search(s) && n != 0)
	{
		n = read (fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			free (buffer);
			free (s);
			return (NULL);
		}
		buffer[n] = '\0';
		s = join (s, buffer);
	}
	free (buffer);
	return (s);
}

char	*checking(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s[i])
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	str = (char *)malloc (sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	while (s[j] != '\0' && s[j] != '\n')
	{
		str[j] = s[j];
		j++;
	}
	if (s[j] == '\n')
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*testing(char *s)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free (s);
		return (NULL);
	}
	str = (char *)malloc (sizeof(char) * (ft_strlen(s) - i));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (s[i] != '\0')
		str[j++] = s[i++];
	str[j] = '\0';
	free (s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*h;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	h = reading (fd, h);
	if (!h)
		return (NULL);
	line = checking (h);
	h = testing (h);
	return (line);
}