#ifndef TINFO
#define TINFO

#include <stdbool.h>

typedef int TInfo;

bool info_greater(TInfo l, TInfo r);
bool info_less(TInfo l, TInfo r);
bool info_equal(TInfo l, TInfo r);
void info_print(TInfo info);
void info_copy(TInfo* l, TInfo* r);
void info_swap(TInfo* l,TInfo* r);

#endif