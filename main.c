#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char **argv)
{
	void *plugin;

	printf("Loading the module\n");

	plugin = dlopen("justprinthi.c", RTLD_NOW);

	if(!plugin){
		printf("fail!\n");
		printf("error: %s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	printf("plugin loaded\n");

	printf("Loading the 'main' method\n");

	int *print;
	print = dlsym(plugin, "main");
	if(!print){
		printf("fail!\n");
		printf("error: %s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	printf("main function loaded\n");
}