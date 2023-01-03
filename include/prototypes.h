#ifndef HEADERS_GEN_H
# define HEADERS_GEN_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

// get_next_line.c
size_t		ft_strlen_gnl(const char *s);
int			ft_belongs_gnl(const char *set, char s);
void		ft_reset_gnl(char *buff);
char		*ft_strjoin_gnl(char const *res, char const *buff);
void		aux_gnl(char **res, char *buff);
char		*one_line_gnl(char *buff, int fd);
char		*get_next_line(int fd);

// help.c
void		print_help(int headers);

// libft.c
int			ft_putstr_fd(int fd, char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strrchr(const char *s, int c);

// put_file_to.c
void		put_file_to(int fd, int headers);

#endif
