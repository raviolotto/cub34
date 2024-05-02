# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

int main(void)
{
	char *str = "pippo";
	char *str2;

	str2 = str;
	while (*str)
		printf("%c\n" , *str++);
	return (0);
}