#include <stdio.h>
#include <stdlib.h>
#include "tinfo.h"

typedef int TInfo;

bool info_greater(TInfo l, TInfo r) {
    return l>r;
}

bool info_less(TInfo l, TInfo r) {
    return l<r;
}

bool info_equal(TInfo l, TInfo r) {
    return l == r;
}

void info_print(TInfo info) {
    printf("%d ", info);
}

void info_copy(TInfo* l, TInfo* r) {
    l = r;
}

void info_swap(TInfo* l, TInfo* r) {
    TInfo temp = *l;
    *l = *r;
    *r = temp;
}
