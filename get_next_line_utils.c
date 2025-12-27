#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (s1_len + 1));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*final_str;
	int		i;
	int		j;
	size_t	strs_len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	strs_len = ft_strlen(s1) + ft_strlen(s2);
	final_str = (char *)malloc(strs_len + 1);
	if (!final_str)
		return (NULL);
	while (s1[i])
		final_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		final_str[j++] = s2[i++];
	final_str[j] = '\0';
	return (final_str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

