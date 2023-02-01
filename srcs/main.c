#include "prototypes.h"

int	file_treatment(int headers, char *path, char *name, int len)
{
	int		fd;
	char	*p;

	if (len + strlen(name) + 2 > MAX_FILENAME_SIZE)
		fprintf(stderr, "path too long: %s/%s\n", path, name);
	else
	{
		path[len] = '/';
		strcpy(path + len + 1, name);
	}
	if ((strrchr(path, '.') && strncmp(strrchr(path, '.') + 1, "c", 2)) != 0
		|| (strrchr(path, '/') && strncmp(strrchr(path, '/') + 1, "main.c", 7) == 0))
		return -1;
	fd = open(path, O_RDONLY);
	if (fd == - 1)
		return -1;
	p = strchr(path + 2, '/');
	if (p == NULL)
		p = path;
	dprintf(headers, "// %s\n", p + 1);
	put_file_to(fd, headers);
	if (close(fd) == -1)
		return -1;
	return 0;
}

void directory_to_header(int headers, char *path)
{
	DIR 			*dir;
	struct dirent	*entry;
	size_t			len;
	char			*name;

	len = strlen(path);
	if (!(dir = opendir(path)))
	{
		fprintf(stderr, "path not found: %s: %s\n", path, strerror(errno));
		return ;
	}
	while ((entry = readdir(dir)) != NULL)
	{
		name = entry->d_name;
		if (entry->d_type == DT_DIR)
		{
			if (!strcmp(name, ".") || !strcmp(name, ".."))
				continue;
			if (len + strlen(name) + 2 > MAX_FILENAME_SIZE)
				fprintf(stderr, "path too long: %s/%s\n", path, name);
			else
			{
				path[len] = '/';
				strcpy(path + len + 1, name);
				directory_to_header(headers, path);
			}
		}
		else
			file_treatment(headers, path, name, len);
	}
	closedir(dir);
}

int	main(int ac, char **av)
{
	int		i;
	int		headers;
	char	path[MAX_FILENAME_SIZE] = "./";

	if (ac <= 1)
		return 0;
	headers = open("prototypes.txt", O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (headers == - 1)
		return -1;
	i = 0;
	while (++i < ac)
	{
		strcpy(path + 2, av[i]);
		directory_to_header(headers, path);
	}
	dprintf(headers, "\n%s", HELP);
	return 0;
}
