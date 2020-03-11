#ifndef DUALCYCLELINKEDLIST_C
#define DUALCYCLELINKEDLIST_C

#include "DualCycleLinkedList.h"

Status InitList_DuL(DuLinkList *L)
{
    *L = (DuLinkList)malloc(sizeof(DuLNode));
    if (!*L) {
        exit(OVERFLOW);
    }
    (*L)->prior = (*L)->next = *L;
    return OK;
}

Status ClearList_DuL(DuLinkList L)
{
    DuLinkList p = L->next;
    if (!L) {
        return ERROR;
    }
    while (p != L) {
        L->next = p->next;
        free(p);
        p = L->next;
    }
    L->prior = L->next = L;
    return OK;
}

void DestroyList_DuL(DuLinkList *L)
{
    ClearList_DuL(*L);
    free(*L);
    *L = NULL;
}

Status ListEmpty_DuL(DuLinkList L)
{
    if (L && L->prior == L && L->next == L) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int ListLength_DuL(DuLinkList L)
{
    if (!L) {
        return 0;
    }
    DuLinkList p = L->next;
    int count = 0;
    while (p != L) {
        ++count;
        p = p->next;
    }
    return count;
}

Status GetElem_DuL(DuLinkList L, int i, LElemType_DC *e)
{
    if (L) {
        DuLinkList p = L->next;
        int count = 1;
        while (p != L && count < i) {
            ++count;
            p = p->next;
        }
        if (p != L) {
            *e = p->data;
            return OK;
        }
    }
    return ERROR;
}

int LocateElem_DuL(DuLinkList L, LElemType_DC cur_e, Status(compare)(LElemType_DC, LElemType_DC))
{
    if (L) {
        DuLinkList p = L->next;
        int count = 0;
        while (p != L) {
            ++count;
            if (!compare(p->data, cur_e)) {
                return count;
            }
            p = p->next;
        }
    }
    return 0;
}

Status PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *prior_e)
{
    if (L) {
        DuLinkList p = L->next;
        while (p != L && p->data != cur_e) {
            p = p->next;
        }
        if (p != L && p->prior != L) {
            *prior_e = p->prior->data;
            return OK;
        }
    }
    return ERROR;
}

Status NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *next_e)
{
    if (L) {
        DuLinkList p = L->next;
        while (p != L && p->data != cur_e) {
            p = p->next;
        }
        if (p != L && p->next != L) {
            *next_e = p->next->data;
            return OK;
        }
    }
    return ERROR;
}

DuLinkList GetElemPtr_DuL(DuLinkList L, int i)
{
    if (L) {
        DuLinkList p = L->next;
        int count = 1;
        while (p != L && count < i) {
            p = p->next;
            ++count;
        }
        if (p != L) {
            return p;
        }
    }
    return NULL;
}

Status ListInsert_DuL(DuLinkList L, int i, LElemType_DC e)
{
    DuLinkList p, q;
    if (!L || i < 1 || i > ListLength_DuL(L) + 1) {
        return ERROR;
    }
    p = GetElemPtr_DuL(L, i);
    if (!p) {
        p = L;
    }
    q = (DuLinkList)malloc(sizeof(DuLNode));
    if (!q) {
        exit(OVERFLOW);
    }
    q->data = e;
    q->next = p;
    q->prior = p->prior;
    p->prior->next = q;
    p->prior = q;
    return OK;
}

Status ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e)
{
    DuLinkList p;
    if (!L || i < 1 || i > ListLength_DuL(L)) {
        return ERROR;
    }
    p = GetElemPtr_DuL(L, i);
    if (p) {
        *e = p->data;
        p->prior->next = p->next;
        p->next->prior = p->prior;
        free(p);
        return OK;
    }
    return ERROR;
}

Status ListTraverse_DuL(DuLinkList L, void(Visit)(LElemType_DC))
{
    if (!L) {
        return ERROR;
    }
    DuLinkList p = L->next;
    while (p != L) {
        Visit(p->data);
        p = p->next;
    }
    return OK;
}

#endif