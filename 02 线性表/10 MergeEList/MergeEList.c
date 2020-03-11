#ifndef MERGEELIST_C
#define MERGEELIST_C

#include "MergeEList.h"

Status MergeEList_L(ELinkList La, ELinkList Lb, ELinkList *Lc, int(compare)(LElemType_E, LElemType_E))
{
    Link ha, hb, pa, pb, q;
    LElemType_E ea, eb;
    if (!InitList_E(Lc)) {
        return ERROR;
    }
    ha = GetHead_E(La);
    hb = GetHead_E(Lb);
    pa = NextPos_E(ha);
    pb = NextPos_E(hb);
    while (!ListEmpty_E(La) && !ListEmpty_E(Lb)) {
        ea = GetCurElem_E(pa);
        eb = GetCurElem_E(pb);
        if (ea <= eb) {
            DelFirst_E(&La, ha, &q);
            InsFirst_E(Lc, Lc->tail, q);
            pa = NextPos_E(ha);
        } else {
            DelFirst_E(&Lb, hb, &q);
            InsFirst_E(Lc, Lc->tail, q);
            pb = NextPos_E(hb);
        }
    }
    if (!ListEmpty_E(La)) {
        Append_E(Lc, pa);
    } else {
        Append_E(Lc, pb);
    }
    FreeNode_E(&ha);
    FreeNode_E(&hb);
    return OK;
}

int Cmp(LElemType_E e1, LElemType_E e2)
{
    return e1 - e2;
}

Status CreateList_ascend(FILE *fp, ELinkList *L, int n)
{
    LElemType_E e;
    if (!InitList_E(L)) {
        return ERROR;
    }
    for (int i = 1; i <= n; ++i) {
        if (Scanf(fp, "%d", &e) != 1) {
            return ERROR;
        }
        ListInsert_L_E(L, i, e);
    }
    return OK;
}

#endif