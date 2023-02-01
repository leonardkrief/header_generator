#ifndef HEADERS_GEN_H
# define HEADERS_GEN_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <fcntl.h>
# include <errno.h>

# define MAX_FILENAME_SIZE 1024
# define HELP "Copy paste these lines to your shell_config file for easier use\n\
\t#prototypes generator\n\
\tmake_ptt() {make re -C ~/path/to/prototypes_generator_directory}\n\
\tptt() {~/path/to/prototypes_executable $@}\n\n\
#############################################\n\
# Léonard KRIEF        lkrief@student.42.fr #\n\
#############################################\n"

// get_next_line.c
size_t		ft_strlen_gnl(const char *s);
int			ft_belongs_gnl(const char *set, char s);
void		ft_reset_gnl(char *buff);
char		*ft_strjoin_gnl(char const *res, char const *buff);
void		aux_gnl(char **res, char *buff);
char		*one_line_gnl(char *buff, int fd);
char		*get_next_line(int fd);

// put_file_to.c
void		put_file_to(int fd, int headers);

#endif
