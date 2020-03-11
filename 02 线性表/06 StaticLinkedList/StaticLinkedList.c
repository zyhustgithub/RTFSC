#ifndef STATICLINKEDLIST_C
#define STATICLINKEDLIST_C

#include "StaticLinkedList.h"

void InitSpace_SL()
{
    for (int i = 0; i <= MAXSIZE - 1; ++i) {
        SPACE[i].cur = i + 1;
    }
    SPACE[MAXSIZE - 1].cur = 0;
}

int Malloc_SL()
{
    int p;
    p = SPACE[0].cur;
    if (p) {
        SPACE[0].cur = SPACE[p].cur;
        return p;
    } else {
        return 0;
    }
}

void Free_SL(int k)
{
    SPACE[k].cur = SPACE[0].cur;
    SPACE[0].cur = k;
}

Status InitList_SL(SLinkList *H)
{
    (*H) = Malloc_SL();
    if (!(*H)) {
        exit(OVERFLOW);
    }
    SPACE[(*H)].cur = 0;
    return OK;
}

Status ClearList_SL(SLinkList H)
{
    int p;
    if (!H) {
        return ERROR;
    }
    p = SPACE[H].cur;
    while (p) {
        SPACE[H].cur = SPACE[p].cur;
        Free_SL(p);
        p = SPACE[H].cur;
    }
    return OK;
}

void DestroyList_SL(SLinkList *H)
{
    ClearList_SL(*H);
    Free_SL(*H);
    *H = 0;
}

Status ListEmpty_SL(SLinkList H)
{
    if (H && SPACE[H].cur == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

Status ListLength_SL(SLinkList H)
{
    int p, count;
    if (!H) {
        return ERROR;
    }
    p = SPACE[H].cur;
    count = 0;
    while (p) {
        ++count;
        p = SPACE[p].cur;
    }
    return count;
}

Status GetElem_SL(SLinkList H, int i, LElemType_S *e)
{
    int count, p;
    if(!H || i < 1 || i > MAXSIZE - 2) {
        return ERROR;
    }
    p = SPACE[H].cur;
    count = 1;
    while (p && count < i) {
        ++count;
        p = SPACE[p].cur;
    }
    if (p && count == i) {
        *e = SPACE[p].data;
        return OK;
    }
    return ERROR;
}

int LocateElem_SL(SLinkList H, LElemType_S e)
{
    int count, p;
    if (!H) {
        return ERROR;
    }
    count = 0;
    p = SPACE[H].cur;
    while (p) {
        ++count;
        if (SPACE[p].data == e) {
            return count;
        }
        p = SPACE[p].cur;
    }
    return 0;
}

Status PriorElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *pre_e)
{
    int count, p, q;
    if (!H) {
        return ERROR;
    }
    p = SPACE[H].cur;
    if (p && SPACE[p].data != cur_e) {
        q = SPACE[p].cur;
        while (q && SPACE[q].data != cur_e) {
            p = q;
            q = SPACE[q].cur;
        }
        if (q) {
            *pre_e = SPACE[p].data;
        }
    }
    return ERROR;
}

Status NextElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *next_e)
{
    int p;
    if (H) {
        p = SPACE[H].cur;
        while (p && SPACE[p].data!=cur_e) {
            p = SPACE[p].cur;
        }
        if (p && SPACE[p].cur) {
            p = SPACE[p].cur;
            *next_e = SPACE[p].data;
            return OK;
        }
    }
    return ERROR;
}

Status ListInsert_SL(SLinkList H, int i, LElemType_S e)
{
    int p, s, count;
    if (i > 0 && H) {
        count = 1;
        p = H;
        while (p && count < i) {
            count++;
            p = SPACE[p].cur;
        }
        if (p) {
            s = Malloc_SL();
            if (!s) {
                exit(OVERFLOW);
            }
            SPACE[s].data = e;
            SPACE[s].cur = SPACE[p].cur;
            SPACE[p].cur = s;
            return OK;
        }
    }
    return ERROR;
}

Status ListDelete_SL(SLinkList H, int i, LElemType_S *e)
{
    int p, q, count;
    if (i > 0 && H) {
        p = H;
        count = 1;
        while (p && count < i) {
            p = SPACE[p].cur;
            ++count;
        }
        if (p && SPACE[p].cur) {
            q = SPACE[p].cur;
            *e = SPACE[q].data;
            SPACE[p].cur = SPACE[q].cur;
            Free_SL(q);
            return OK;
        }
    }
    return ERROR;
}

Status ListTraverse_SL(SLinkList H, void(Visit)(LElemType_S))
{
    int p;
    if (H) {
        p = SPACE[H].cur;
        while (p) {
            Visit(SPACE[p].data);
            p = SPACE[p].cur;
        }
        return OK;
    }
    return ERROR;
}

#endif
