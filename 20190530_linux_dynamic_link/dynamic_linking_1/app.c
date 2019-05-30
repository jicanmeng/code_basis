#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main ()
{
	char *error;
	int (*func_add)(int, int);
	float (*func_div)(float, float);

	void *handle = dlopen("./libtest.so", RTLD_LAZY);
	if (!handle) {
		fprintf(stderr, "%s:%d: %s\n", __func__, __LINE__, dlerror());
		exit(EXIT_FAILURE);
	}

	*(void **)(&func_add) = dlsym(handle, "pz_add");
	if ((error = dlerror()) != NULL)  {
		fprintf(stderr, "%s:%d: %s\n", __func__, __LINE__, error);
		dlclose(handle);
		exit(EXIT_FAILURE);
	}

	*(void **)(&func_div) = dlsym(handle, "pz_div");
	if ((error = dlerror()) != NULL)  {
		fprintf(stderr, "%s:%d: %s\n", __func__, __LINE__, error);
		dlclose(handle);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*func_add)(2, 4));
	printf("%f\n", (*func_div)(3.0f,4.0f));
	dlclose(handle);

    return 0;
}
