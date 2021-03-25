#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main()
{
	char	*name;
	int		ttyinfo;
	int		tmp;

	//isatty and ttyname <unistd.h>
	ttyinfo = isatty(STDIN_FILENO);
	printf("ttyinfo: %d\n", ttyinfo);
	name = ttyname(STDIN_FILENO);
	printf("ttyname: %s\n", name);

	tmp = open("test2.txt", O_CREAT | O_APPEND | O_WRONLY, 0755);
	ttyinfo = isatty(tmp);
	printf("ttyinfo: %d\n", ttyinfo);
	name = ttyname(tmp);
	printf("ttyname: %s\n", name);
	close(tmp);

	//ttyslot <unistd.h>
	int slot = ttyslot();
	printf("slot : %d\n", slot);

	//ioctl <ioctl.h>



}
