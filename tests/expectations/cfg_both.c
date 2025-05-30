#if 0
DEF PLATFORM_UNIX = 0
DEF PLATFORM_WIN = 0
DEF X11 = 0
DEF M_32 = 0
#endif


#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#if (defined(PLATFORM_WIN) || defined(M_32))
enum BarType {
  A,
  B,
  C,
};
typedef uint32_t BarType;
#endif

#if (defined(PLATFORM_UNIX) && defined(X11))
enum FooType {
  A,
  B,
  C,
};
typedef uint32_t FooType;
#endif

#if (defined(PLATFORM_UNIX) && defined(X11))
typedef struct FooHandle {
  FooType ty;
  int32_t x;
  float y;
} FooHandle;
#endif

enum C_Tag {
  C1,
  C2,
#if defined(PLATFORM_WIN)
  C3,
#endif
#if defined(PLATFORM_UNIX)
  C5,
#endif
};
typedef uint8_t C_Tag;

#if defined(PLATFORM_UNIX)
typedef struct C5_Body {
  C_Tag tag;
  int32_t int_;
} C5_Body;
#endif

typedef union C {
  C_Tag tag;
#if defined(PLATFORM_UNIX)
  C5_Body c5;
#endif
} C;

#if (defined(PLATFORM_WIN) || defined(M_32))
typedef struct BarHandle {
  BarType ty;
  int32_t x;
  float y;
} BarHandle;
#endif

typedef struct ConditionalField {
#if defined(X11)
  int32_t field
#endif
  ;
} ConditionalField;
#define ConditionalField_ZERO (ConditionalField){ .field = 0 }
#define ConditionalField_ONE (ConditionalField){ .field = 1 }

typedef struct Normal {
  int32_t x;
  float y;
} Normal;

#if defined(PLATFORM_WIN)
extern int32_t global_array_with_different_sizes[2];
#endif

#if defined(PLATFORM_UNIX)
extern int32_t global_array_with_different_sizes[1];
#endif

#if (defined(PLATFORM_UNIX) && defined(X11))
void root(struct FooHandle a, union C c);
#endif

#if (defined(PLATFORM_WIN) || defined(M_32))
void root(struct BarHandle a, union C c);
#endif

void cond(struct ConditionalField a);

#if defined(PLATFORM_WIN)
extern int32_t foo(void);
#endif

#if defined(PLATFORM_WIN)
extern void bar(struct Normal a);
#endif
