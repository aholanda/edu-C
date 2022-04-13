#include <stdio.h>
#include <stdlib.h>
#include "mem.h"

 void *mem_alloc(unsigned long nbytes, const char *filename, unsigned long line)
	{
		void *ptr;

		ptr = calloc(1, nbytes);
		assert(ptr != NULL);

		return ptr;
	}

 void *mem_calloc(unsigned long count, unsigned long nbytes, 
		   const char *filename, unsigned long line)
	{
		void *ptr;

		ptr = calloc(count, nbytes);
		assert(ptr != NULL);

		return ptr;
	}

 void *mem_resize(void*ptr, unsigned long nbytes, 
		   const char *filename, unsigned long line)
	{
		assert(ptr != NULL);

		ptr = realloc(ptr, nbytes);
		assert(ptr != NULL);

		return ptr;
	}


  void mem_free(void *ptr, const char*filename, unsigned long line)
	{
		assert(ptr != NULL);
		free(ptr);
	}

