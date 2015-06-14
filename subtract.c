#include <stdio.h>
#include <stdlib.h>

double Do(int argc, double * argv)
{
	int i;

	printf("Subtracting the following %d arguments: %f", argc, argv[0]);

	for (i = 1; i < argc; ++i)
	{
		printf(", %f", argv[i]);
	}

	printf("\n");

	double result = argv[0];

	for (i = 1; i < argc; ++i)
	{
		result -= argv[i];
	}

	return(result);
}