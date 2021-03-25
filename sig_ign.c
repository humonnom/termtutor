#include <stdio.h>
#include <termios.h>


int main()
{
	struct termios	new_set;
	struct termios	old_set;
	
	char buf[80]; 
	tcgetattr(0, &old_set);
	new_set = old_set;
	new_set.c_lflag &= (~ISIG);
	tcsetattr(0, TCSANOW, &new_set);
	fgets(buf, 80, stdin);
	fputs(buf, stdout);
	tcsetattr(0, TCSANOW, &old_set);
}
