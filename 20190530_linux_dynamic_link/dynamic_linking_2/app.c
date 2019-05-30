#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "test1.h"

int main ()
{
	char *error;
	int status = -EINVAL;
	struct pz_struct_t *hmi = NULL;
	char *path = "./libtest.so";

	void *handle = dlopen(path, RTLD_LAZY);
	if (!handle) {
		fprintf(stderr, "%s:%d: %s\n", __func__, __LINE__, dlerror());
		status = -EINVAL;
        goto done;
	}

    const char *sym = HAL_MODULE_INFO_SYM_AS_STR;
    hmi = (struct pz_struct_t *)dlsym(handle, sym);
    if (hmi == NULL) {
        fprintf(stderr, "load: couldn't find symbol %s", sym);
        status = -EINVAL;
		goto done;
    }

	fprintf(stderr, "pz_add(3,4) is %d.\n",	hmi->pz_add(3,4));
	fprintf(stderr, "pz_sub(3.0f,4.0f) is %f.\n", hmi->pz_sub(3.0f,4.0f));
	status = 0;

    done:
    if (status != 0) {
        hmi = NULL;
        if (handle != NULL) {
            dlclose(handle);
            handle = NULL;
        }
    } else {
        fprintf(stderr, "loaded HAL path=%s handle=%p.\n",
                path, handle);
    }

    return 0;
}
