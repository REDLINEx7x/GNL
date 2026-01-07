/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:13:41 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/06 22:21:02 by moamhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	if (!s1)
		return (NULL);
	s2 = malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*final;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}
	if (!s2)
		return (free(s1), NULL);
	final = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!final)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1[i])
		final[j++] = s1[i++];
	i = 0;
	while (s2[i])
		final[j++] = s2[i++];
	final[j] = '\0';
	return (free(s1), final);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	hold;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	hold = c;
	while (s[i])
	{
		if (s[i] == hold)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == hold)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t	i;
	char	*sub_str;
	size_t	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub_str = (char *)malloc(len + 1);
	if (!sub_str)
		return (NULL);
	while (i < len)
	{
		sub_str[i] = s[start];
		i++;
		start++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
