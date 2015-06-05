#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int numberOfArgs = argc-1;

	int args[numberOfArgs];

	// skip the first argument
	argv++;

	// while argc > 1 - the number of args have effectively been reduced because the first one is skipped.
	while(argc-- -1){
		int position = numberOfArgs - argc;
		args[position] = atoi(argv[position]);
	}

	// numberOfArgs is used because sizeof(args) is not usable because of array decay. (???)
	int i;
	for (i = 0; i < numberOfArgs; ++i)
	{
		printf("arg: %d\n", args[i]);
	}

    exit(EXIT_SUCCESS);
}