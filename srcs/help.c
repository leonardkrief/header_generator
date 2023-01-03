#include "prototypes.h"

void	print_help(int headers)
{
	ft_putstr_fd(headers, "Copy paste these lines to your shell_config file for easier use\n");
	ft_putstr_fd(headers, "\t#prototypes generator\n");
	ft_putstr_fd(headers, "\tmake_prototypes() {make re -C ~/path/to/prototypes_generator_directory}\n");
	ft_putstr_fd(headers, "\tprototypes() {~/path/to/prototypes_executable $@}\n\n");
	ft_putstr_fd(headers, "##############################################\n");
	ft_putstr_fd(headers, "# Léonard KRIEF        leonardkrief@yahoo.fr #\n");
	ft_putstr_fd(headers, "##############################################\n");
}
