#include "h_fillit.h"

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, const char *src, size_t num)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < num)
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\0')
	{
		while (i < num)
			dest[i++] = '\0';
	}
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char*)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char*)&str[i]);
	return (NULL);
}

char	*ft_strtrim(char const *s)
{
	char	*start;
	char	*end;
	char	*ns;
	int		n;

	if (s == NULL)
		return (NULL);
	start = (char *)s;
	end = ft_strchr(s, '\0');
	end--;
	while (*start == '.')
		start++;
	while ((*end == '.') && end > start)
		end--;
	n = end - start + 1;
	ns = (char *)malloc(n + 1);
	if (ns)
	{
		ns = ft_strncpy(ns, start, n);
		ns[n] = '\0';
	}
	return (ns);
}

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 || *s2)
		{
			if (*s1++ != *s2++)
				return (0);
		}
	}
	return (1);
}
