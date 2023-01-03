#include "prototypes.h"

int	ft_putstr_fd(int fd, char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (-1);
	while (str[len])
		len++;
	write(fd, str, len);
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	else
		return (((unsigned char) s1[i]) - ((unsigned char) s2[i]));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(*join) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = '\0';
	return (join);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = NULL;
	while (s[i])
	{
		if (s[i] == (char) c)
			p = ((char *)s) + i;
		i++;
	}
	if (s[i] == (char) c)
		p = ((char *)s) + i;
	return (p);
}
