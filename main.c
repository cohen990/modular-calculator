#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char **argv)
{
	void *plugin;

	printf("Loading the module\n");

	plugin = dlopen("./justprinthi.so", RTLD_NOW);

	if(!plugin){
		printf("fail!\n");
		printf("error: %s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	printf("plugin loaded\n");

	printf("Loading the 'main' method\n");

	int (*Do)();
	Do = dlsym(plugin, "Do");
	if(!Do){
		printf("fail!\n");
		printf("error: %s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	printf("'Do' function loaded\n");

	printf("** Executing **");

	Do();
}