#include "prototypes.h"

void	put_file_to(int fd, int headers)
{
	int		i;
	char	*s1;
	char	*s2;

	s1 = get_next_line(fd);
	s2 = get_next_line(fd);
	while (s2 != NULL)
	{
		while (s2 != NULL && (strncmp(s2, "{\n", 3) != 0))
		{
			free(s1);
			s1 = s2;
			s2 = get_next_line(fd);
		}
		i = 0;
		if (s1 && s2 && strncmp(s1, "static ", 7))
		{
			while (s1[i] && s1[i] != '\n')
				write(headers, &s1[i++], 1);
			dprintf(headers, ";\n");
		}
		while (s2 != NULL && (strncmp(s2, "}\n", 3) != 0))
		{
			free(s1);
			s1 = s2;
			s2 = get_next_line(fd);
		}
	}
	if (s1)
		free(s1);
	dprintf(headers, "\n");
}