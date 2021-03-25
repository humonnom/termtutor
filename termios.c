#include <stdio.h>
#include <fcntl.h>
#include <termios.h>

int main()
{
	struct termios *term;
	int				fd;

	fd = open("test2.txt", O_CREAT | O_APPEND | O_WRONLY, 0755);
	//get terminal info
	if (tcgetattr(fd, term) == -1)
		printf("error\n");
	//modify terminal info
	if (tcsetattr(fd, TCSANOW, term) == -1)
		printf("error\n");
	return (0);
}
