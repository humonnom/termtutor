#include <stdlib.h>
#include <stdio.h>

int main()
{
	char	*env;

	env = getenv("TERM");
	printf("get_env: %s\n", env);
}
