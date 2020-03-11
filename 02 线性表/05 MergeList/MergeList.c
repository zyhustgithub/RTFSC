#ifndef MERGELIST_C
#define MERGELIST_C

#include "MergeList.h"

void MergeList_L(LinkList La, LinkList *Lb, LinkList *Lc)
{
    LinkList pa, pb, pc;
    pa = La->next;
    pb = (*Lb)->next;
    pc = (*Lc) = La;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pa = pa->next;
            pc = pc->next;
        } else {
            pc->next = pb;
            pb = pb->next;
            pc = pc->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(*Lb);
    *Lb = NULL;
}

#endif
