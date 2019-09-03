#include "get_next_line.h"
#include <stdio.h>
size_t	find_newline(char *store)
{
	int		counter;

	counter = 0;
	while (store[counter] != '\n')
		counter++;
	return (counter);

	//searches for a '\n' characher in store and when found it returns the position of it.
}

int readline(char **store, char **line) //function to read until a '\n' is found
{
	char	*temp;
	int		pos;
	//char	*stackbuff;
	pos = 0;
	if (ft_strchr(*store, '\n') != NULL)
	{
		pos = find_newline(*store); //takes the index number where '\n' is found

		*line = ft_strsub(*store, 0, pos); //move all character until '\n' into store
		temp = ft_strdup(ft_strchr(*store, '\n') + 1); // left over character after '\n' but before chunk size is reached are copied to tem
		ft_strdel(store); //free store
		*store = temp; // point store to temp.
	}
	else
	{
		*line = ft_strdup(*store); // if no '\n' is found but bytes is > 0 copy from store to line
		ft_strdel(store);
	}
	return(1);
}

int get_next_line(int fd, char **line)
{
	char		stackbuff[BUFF_SIZE + 1];
	static char	*store;
	int			bytes;
	char		*temp;

	if (store == NULL)
		store = ft_strnew(0);
	while ((bytes = read(fd, stackbuff, BUFF_SIZE)) > 0)
	{
		stackbuff[bytes] = '\0'; //terminating the characters read by 'read' to be a string so we can work on it"
		temp = ft_strjoin(store, stackbuff);
		ft_strdel(&store);
		store = temp;
	}
	if	(bytes < 0 )
		return(-1);
	else if	(bytes == 0 && ft_strlen(store) == 0)
		return(0);
	else
		return	(readline(&store, line));
}
