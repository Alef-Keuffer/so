#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

int main (int argc, char *argv[])
{
  void *handle;
  char *error;
  double (*cosine) (double);
  int (*func) (int, char*[]);

  char command[1024];
  handle = dlopen ("/home/alef/Documents/coding/c/so/cmake-build-debug/libfichas.so", RTLD_LAZY);
  if (!handle)
	{
	  fprintf (stderr, "%s\n", dlerror ());
	  exit (EXIT_FAILURE);
	}

  dlerror ();    /* Clear any existing error */

  /* Writing: cosine = (double (*)(double)) dlsym(handle, "cos");
	 would seem more natural, but the C99 standard leaves
	 casting from "void *" to a function pointer undefined.
	 The assignment used below is the POSIX.1-2003 (Technical
	 Corrigendum 1) workaround; see the Rationale for the
	 POSIX specification of dlsym(). */

  //*(void **)(&cosine) = dlsym (handle, "cos");
  *(void **)(&func) = dlsym (handle, argv[1]);
  if ((error = dlerror ()) != NULL)
	{
	  fprintf (stderr, "%s\n", error);
	  exit (EXIT_FAILURE);
	}

  (*func) (argc, argv);

  dlclose (handle);
  exit (EXIT_SUCCESS);
}

