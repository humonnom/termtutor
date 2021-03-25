#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char	*name;
	int		valid_flag;
	int		tmp;

//isatty and ttyname <unistd.h>
	printf("========using isatty and ttyname=======\n");
	//STDIN
	printf("1.STDIN\n");
	valid_flag = isatty(STDIN_FILENO);
	printf("	is a tty: %d\n", valid_flag);

	name = ttyname(STDIN_FILENO);
	printf("	terminal name: %s\n", name);

	//file descriptor
	printf("2.file descriptor(open file: test.txt)\n");
	tmp = open("test.txt", O_CREAT | O_APPEND | O_WRONLY, 0755);
	
	valid_flag = isatty(tmp);
	printf("	is a tty?: %d\n", valid_flag);
	
	name = ttyname(tmp);
	printf("	terminal name: %s\n", name);
	
	close(tmp);

//ttyslot <unistd.h>
	printf("========using ttyslot=======\n");
	int slot = ttyslot();
	printf("current user's index in user data base: %d\n", slot);
}
