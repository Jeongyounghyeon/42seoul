// #include <string.h>
// #include <fcntl.h> 
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <time.h>

// static int test(int fd, char *buff)
// {
//     return (read(fd, buff, BUFF_SIZE));
// }

// int main()
// {
// 	char   buff[BUFF_SIZE];
// 	int    fd;
// 	ssize_t res;
	
// 	fd = open( "test.txt", O_RDONLY);
// 	while (0 != (res = test(fd, buff))){
// 		printf("\nsize = %zd\n", res);
// 		sleep(1);
// 	}

// 	close(fd);
// 	return 0;
// }

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> 

int main()
{
	char  	buff[BUFFER_SIZE];
	int   	fd;
	char 	res[12];
	char	c;

	/*
	fd = open( "test.txt", O_RDONLY);
	while (0 != (res = get_next_line(fd))){
		printf("%s", res);
	}
	*/

	buff[2] = 0;
	fd = open( "test.txt", O_RDONLY);
	while (0 < (read(fd, res, 4))){
		printf("%s", res);
	}

	return 0;
}