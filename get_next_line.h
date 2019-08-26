#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42

#include "libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	get_next_line(int fd, char **line);

#endif
