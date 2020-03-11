#ifndef DIFFERENCE_C
#define DIFFERENCE_C

#include "Difference.h"

void Difference(SLinkList *S, LElemType_S A[], int len_A, LElemType_S B[], int len_B)
{
    int i, j;
    int pos;
    LElemType_S e;
    InitSpace_SL();
    *S = Malloc_SL();
    if (!(*S)) {
        exit(OVERFLOW);
    }
    SPACE[*S].cur = 0;
    for (i = 0, j = 0; i < len_A; ++i) {
        ListInsert_SL(*S, ++j, A[i]);
    }
    for (i = 0; i < len_B; ++i) {
        if ((pos = LocateElem_SL(*S, B[i])) == 0) {
            ListInsert_SL(*S, ++j, B[i]);
        } else {
            ListDelete_SL(*S, pos, &e);
            --j;
        }
    }
}

void difference(SLinkList *S, LElemType_S A[], int len_A, LElemType_S B[], int len_B)
{
    int i, j, k, p;
    int pos;
    SLinkList r;

    InitSpace_SL();
    *S = Malloc_SL();
    if (!(*S)) {
        exit(OVERFLOW);
    }
    SPACE[*S].cur = 0;
    r = *S;

    for (i = 0; i < len_A; ++i) {
        j = Malloc_SL();
        SPACE[j].data = A[i];
        SPACE[j].cur = SPACE[r].cur;
        SPACE[r].cur = j;
        r = j;
    }
    for (i = 0; i < len_B; ++i) {
        p = *S;
        k = SPACE[*S].cur;
        while (k && SPACE[k].data != B[i]) {
            p = k;
            k = SPACE[k].cur;
        }
        if (!k) {
            j = Malloc_SL();
            SPACE[j].data = B[i];
            SPACE[j].cur = SPACE[r].cur;
            SPACE[r].cur = j;
            r = j;
        } else {
            SPACE[p].cur = SPACE[k].cur;
            if(k == r) {
                r = p;
            }
            Free_SL(k);
        }
    }
}

#endif