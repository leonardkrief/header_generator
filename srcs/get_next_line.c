#include "../include/headers_gen.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_belongs_gnl(const char *set, char s)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

void	ft_reset_gnl(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	while (buff[i])
		buff[j++] = buff[i++];
	buff[j] = '\0';
}

char	*ft_strjoin_gnl(char const *res, char const *buff)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (buff[0] == 0)
		return (NULL);
	if (res == NULL)
		join = malloc(sizeof(*join) * (ft_strlen_gnl(buff) + 1));
	else
		join = malloc(sizeof(*join) * (ft_strlen_gnl(res) + ft_strlen_gnl(buff) + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (res && res[i])
		join[j++] = res[i++];
	i = 0;
	while (buff[i] && buff[i] != '\n')
		join[j++] = buff[i++];
	if (buff[i] == '\n')
		join[j++] = '\n';
	join[j] = '\0';
	return (join);
}

void	aux_gnl(char **res, char *buff)
{
	char	*tmp;

	tmp = *res;
	*res = ft_strjoin_gnl(*res, buff);
	if (tmp)
		free(tmp);
}

char	*one_line_gnl(char *buff, int fd)
{
	int		ret;
	char	*res;

	res = NULL;
	ret = 0;
	aux_gnl(&res, buff);
	if (!ft_belongs_gnl(buff, '\n'))
		ret = read(fd, buff, BUFFER_SIZE);
	while (ret && !ft_belongs_gnl(buff, '\n'))
	{
		buff[ret] = '\0';
		aux_gnl(&res, buff);
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (ret)
	{
		buff[ret] = '\0';
		aux_gnl(&res, buff);
	}
	ft_reset_gnl(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];

	if (BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	return (one_line_gnl(buff, fd));
}