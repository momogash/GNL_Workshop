#include "get_next_line.h"

//copy-paste (be outside of insert mode)
// go to start point - ma
// go to end point - d'a
// go to paste point - p

size_t	find_newline(char *store)
{
	//size_t	newline_len;
	int		counter;

	counter = 0;
	//1. Check how long string is
	//2. while (not at end of ft_strlen) search for '\n'
	while (store[counter] != '\n')
		counter++;
	return (counter);

	/* newline_len = ft_strlen(store) - ft_strlen(ft_strchr(store, '\n'));
	newline_len = ft_strchr(store, '\n') - store; */
	//3. Return position of found newline
}

int get_next_line(int fd, char **line)
{
	//char *buff;
	char		stackbuff[BUFF_SIZE + 1];
	static char	*store;
	//char		*newline;
	int			bytes;
	int			line_pos;

	line_pos = 0;

	//buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	//bytes = read(fd, stackbuff, BUFF_SIZE);
	if (store == NULL)
		store = ft_strnew(0);
	while ((bytes = read(fd, stackbuff, BUFF_SIZE)) > 0)
	{
		stackbuff[bytes] = '\0';
		store = ft_strjoin(store, stackbuff);
		if (ft_strchr(stackbuff, '\n') != NULL)
		{
			line_pos = find_newline(store);
			ft_putendl("A newline has been found");
			*line = ft_strsub(store, 0, line_pos);
			store = ft_strsub(store, line_pos + 1, (ft_strlen(store) - 1) - line_pos);
			//*line = ft_strdup(store);
			return (1);
		}
	}
	return (0);
}
