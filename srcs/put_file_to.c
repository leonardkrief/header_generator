#include "prototypes.h"

static void	get_next_line_special(const int fd, char *s[4])
{
	s[0] = s[1];
	s[1] = s[2];
	s[2] = s[3];
	s[3] = get_next_line(fd);
}

static void	put_noendl(const int fd, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	write(fd, s, i);
}

void	put_file_to(int fd, int headers)
{
	char	*s[4];

	s[0] = get_next_line(fd);
	s[1] = get_next_line(fd);
	s[2] = get_next_line(fd);
	s[3] = get_next_line(fd);
	while (s[3] != NULL)
	{
		while (s[3] != NULL && (strncmp(s[3], "{\n", 3) != 0))
		{
			free(s[0]);
			get_next_line_special(fd, s);
		}
		if (s[3] && strncmp(s[0], "static ", 7)
			&& strncmp(s[1], "static ", 7)
			&& strncmp(s[2], "static ", 7))
		{
			if (s[1][0] == '\n' || !strncmp(s[0], "//", 2))
				put_noendl(headers, s[2]);
			else if (s[0][0] == '\n' || !strncmp(s[1], "//", 2))
			{
				dprintf(headers, "%s", s[1]);
				put_noendl(headers, s[2]);
			}
			else
			{
				dprintf(headers, "%s", s[0]);
				dprintf(headers, "%s", s[1]);
				put_noendl(headers, s[2]);
			}
			dprintf(headers, ";\n");
		}
		while (s[3] != NULL && (strncmp(s[3], "}\n", 3) != 0))
		{
			free(s[0]);
			get_next_line_special(fd, s);
		}
	}
	if (s[0])
		free(s[0]);
	if (s[1])
		free(s[1]);
	if (s[2])
		free(s[2]);
	if (s[3])
		free(s[3]);
	dprintf(headers, "\n");
}