#include <curses.h>
#include <term.h>
#include <termios.h>
#include <stdlib.h>
#include <stdio.h>

static char entry[2048];

int main ()
{
	char *termtype; 
	int success;
	
	termtype = NULL;
	termtype = getenv("TERM");
	printf("termtype:%s\n", termtype);
	if (!termtype)
		printf ("Specify a terminal type with `setenv TERM <yourtype>'.\n");
	success = tgetent(entry, termtype);
	//success = tgetent(term_buffer, termtype);
	if (success < 0)
		printf ("Could not access the termcap data base.\n");
	else if (success == 0)
		printf ("Terminal type `%s' is not defined.\n", termtype);
	else
		printf("success: %d\n", success);
}
