#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

int main(int argc, char **argv)
{
	int i;
	char * mathematicalFunction = argv[1];
	double args[argc -2];

	for (i = 0; i < sizeof(mathematicalFunction); ++i)
	{
		mathematicalFunction[i] = tolower(mathematicalFunction[i]);
	}

	for (i = 2; i < argc; ++i)
	{
		double arg = atof(argv[i]);

		args[i-2] = arg;
		printf("argv %f\n", arg);
	}

	void *plugin;

	printf("Loading the module\n");

	char filename[5 + sizeof(mathematicalFunction)];

	strcpy(filename, "./");
	strcat(filename, mathematicalFunction);
	strcat(filename, ".so");

	printf("Attempting to load %s\n", filename);

	plugin = dlopen(filename, RTLD_LAZY);

	if(!plugin){
		printf("fail!\n");
		printf("error: %s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	printf("plugin loaded\n");

	printf("Loading the 'Do' method\n");

	double (*Do)(int, double[]);
	Do = dlsym(plugin, "Do");
	if(!Do){
		printf("fail!\n");
		printf("error: %s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	printf("'Do' function loaded\n");

	printf("** Executing **");

	double result = Do(argc - 2, args);

	printf("Result of operation: %f\n", result);

	printf("Closing the plugin\n");

	dlclose(plugin);
}