
#include "get_next_line.h"


int main(int ac, char **av)
{
	int fd;
	char *line;
	int result;
	ac = 0;

	fd = open(av[1], O_RDONLY);
	while ((result = get_next_line(fd, &line)) > 0)
	{
		ft_putendl(line);
		//ft_putendl("END OF BUFF_SIZE");
	}
	//close(fd);
	return 0;
}
