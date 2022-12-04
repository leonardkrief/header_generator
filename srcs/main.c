#include "../include/headers_gen.h"

int	main(int ac, char **av)
{
	int	i;
	int	fd;
	int	headers;
	char	*file;

	i = 0;
	headers = open("prototypes.txt", O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (headers == - 1)
		return (-1);
	while (++i < ac)
	{
		file = ft_strjoin("./", av[i]);
		if (!file)
			return (-1);
		fd = open(file, O_RDONLY);
		free(file);
		if (fd == - 1)
			return (-1);
		ft_putstr_fd(headers, "// ");
		ft_putstr_fd(headers, ft_strrchr(av[i], '/') + 1);
		ft_putstr_fd(headers, "\n");
		put_file_to(fd, headers);
		if (close(fd) == -1)
			return (-1);
	}
}