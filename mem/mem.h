/* Memory management. */

#ifndef __MEM__H__
#define __MEM__H__


/* Default scheme. */

  extern@, __malloc void *mem_alloc(unsigned long nbytes, 
				    const char *filename, 
				    unsigned long line);@/
  extern@, __malloc void *mem_calloc(unsigned long count,
				     unsigned long nbytes,
				     const char *filename, 
				     unsigned long line);@/
  extern@, __malloc void *mem_resize(void*ptr, unsigned long nbytes, 
				     const char *filename, unsigned long line);@/
  extern void mem_free(void*, const char*filename,	\
		       unsigned long line);@/
  
/* Some macros are provided to simplify the prototype, 
with the number of line and the name of it getting of 
C macros. */

 
#define ALLOC(nbytes)				\
  mem_alloc((nbytes), __FILE__, __LINE__)
#define CALLOC(count, nbytes)		\
  mem_calloc((count), (nbytes), __FILE__, __LINE__)
#define NEW(ptr) ((ptr) = ALLOC((unsigned long)sizeof *(ptr)))
#define NEW0(ptr) ((ptr) = CALLOC(1, (unsigned long)sizeof *(ptr)))
#define FREE(ptr)	mem_free((ptr), __FILE__, __LINE__)
#define RESIZE(ptr, nbytes)						\
  ((ptr) = mem_resize((ptr), (nbytes), __FILE__, __LINE__))


/* Error management. This module handles errors from programs.
 Commonly assertions are used to test that some expected state 
 (pre condition) is correct. We redefine |assert| to become it 
 appropriate to change the way the errors are caught. */

  
#undef assert
#ifdef NDEBUG
#define assert(e) ((void)0)
#else
extern void assert(int e);
#define assert(e)							\
     ((void)((e) || (fprintf(stderr, "%s:%d Assertion failed: %s\n",	\
			     __FILE__, __LINE__, #e), abort(), 0)))
#endif


/* GCC extensions. The {\tt \_\_atribute\_\_} syntax can be hidden
by some macros that are loaded when the compiler is {\tt gcc}.
These extensions were defined based on the book "Linux System Programming"
by Robert Love. */

#if __GNUC__ >= 3
@<GCC preprocessor macros@>@;
#define __pure  __attribute__ ((pure))
#define __const  __attribute__ ((const))
#define __noreturn  __attribute__ ((noreturn))
#define __malloc  __attribute__ ((malloc))
#define __must_check  __attribute__ ((warn_unused_result))
#define __deprecated  __attribute__ ((deprecated))
#define __used  __attribute__ ((used))
#define __unused  __attribute__ ((unused))
#define __packed  __attribute__ ((packed))
#define __align(x)  __attribute__ ((aligned (x)))
#define __align_max  __attribute__ ((aligned))
#define __likely  __builtin_expect(!!(x), 1)
#define __unlikely  __builtin_expect(!!(x), 0)
#else
#define __noinline      /* no noinline */
#define __pure          /* no pure */
#define __const  /* no const */
#define __noreturn /* no return */
#define __malloc  /* no malloc */
#define __must_check  /* no must\_check */
#define __deprecated  /* no deprecated */
#define __used  /* no used */
#define __unused /* no unused */
#define __packed /* no packed */
#define __align(x)  /* no align(x) */
#define __align_max  /* no align\_max */
#define __likely  /* no likely */
#define __unlikely /* no unlikely */
#endif

/* Inline. The |inline| macro forces the declared function to be copied where it
  is used. By default, the {\tt inline} keyword is only a hint to the compiler.
  The |noinline| macro goes on the opposite direction, the declared function is
  forced to never be copied where it is used. */

#undef inline
#define inline inline __attribute__ ((always_inline))
#define __noinline  __attribute__ ((noinline))

  
#endif
