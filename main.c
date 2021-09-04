#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;

	fd = open("file.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
}
