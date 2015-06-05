#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char **argv)
{
	void *plugin;

	plugin = dlopen("justprinthi.exe", RTLD_NOW);

	if(!plugin){
		printf("fail!\n");
		exit(EXIT_FAILURE);
	}
	printf("plugin loaded\n");

	void *print;

	print = dlsym(plugin, "print");
	if(!print){
		printf("fail!\n");
		exit(EXIT_FAILURE);
	}

	printf("main function loaded\n");
}