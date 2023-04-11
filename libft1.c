/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:47:39 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/10 23:38:01 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char			*cp;
	unsigned int	i;

	i = 0;
	cp = (char *)malloc(sizeof (char) * (ft_strlen(s1) + 1));
	if (!cp)
		return (NULL);
	while (s1[i] != '\0')
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*st;

	j = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	st = (char *)malloc(len + 1);
	if (!st)
		return (NULL);
	i = start;
	while (start < len + i && s[start] != '\0')
	{
		st[j] = s[start];
		j++;
		start++;
	}
	st[j] = '\0';
	return (st);
}

static	int	nbr_word(char const *s, char c)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w);
}

void	free_table(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
}

static	char	**result(char const *s, char c, char **k, int i)
{
	int	j;
	int	l;
	int	d;

	l = 0;
	d = nbr_word (s, c);
	while (s[i] && l < d)
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			j++;
		}
		k[l++] = ft_substr (s, i - j, j);
		if (!k)
		{
			free_table (k);
			return (NULL);
		}
	}
	k[l] = 0;
	return (k);
}

char	**ft_split(char	const	*s, char c)
{
	char	**k;

	if (!s)
		return (NULL);
	k = (char **) malloc((1 + nbr_word(s, c)) * sizeof(char *));
	if (!k)
		return (NULL);
	return (result(s, c, k, 0));
}