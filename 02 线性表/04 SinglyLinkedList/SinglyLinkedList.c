#ifndef SINGLYLINKEDLIST_C
#define SINGLYLINKEDLIST_C

#include "SinglyLinkedList.h"

Status InitList_L(LinkList *L)
{
    (*L) = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL) {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
    return OK;
}

Status ClearList_L(LinkList L)
{
    if (!L) {
        return ERROR;
    }
    LinkList p = L->next;
    while (p) {
        L->next = p->next;
        free(p);
        p = L->next;
    }
    L->next = NULL;
    return OK;
}

void DestroyList_L(LinkList *L)
{
    ClearList_L(*L);
    free(*L);
    *L = NULL;
}

Status ListEmpty_L(LinkList L)
{
    if (L && L->next == NULL) {
        return OK;
    } else {
        return ERROR;
    }
}

int ListLength_L(LinkList L)
{
    LinkList p = L->next;
    int count = 0;
    while (p) {
        ++count;
        p = p->next;
    }
    return count;
}

Status GetElem_L(LinkList L, int i, LElemType_L *e)
{
    LinkList p = L->next;
    int count = 1;
    while (p && count < i) {
        p = p->next;
        ++count;
    }
    if (!p) {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

int LocateElem_L(LinkList L, LElemType_L cur_e, Status(compare)(LElemType_L, LElemType_L))
{
    LinkList p = L->next;
    int count = 0;
    while (p) {
        ++count;
        if (compare(cur_e, p->data)) {
            return count;
        }
        p = p->next;
    }
    return 0;
}

Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *prior_e)
{
    LinkList p = L->next;
    if (p && p->data != cur_e) {
        while (p->next && p->next->data != cur_e) {
            p = p->next;
        }
        if (p->next) {
            *prior_e = p->data;
            return OK;
        }
    }
    return ERROR;
}

Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e)
{
    LinkList p = L->next;
    while (p && p->data != cur_e) {
        p = p->next;
    }
    if (p && p->next) {
        *next_e = p->next->data;
        return OK;
    }
    return ERROR;
}

Status ListInsert_L(LinkList L, int i, LElemType_L e)
{
    LinkList p, q;
    p = L;
    int count = 1;
    while (p && count < i) {
        p = p->next;
        ++count;
    }
    if (p) {
        q = (LinkList)malloc(sizeof(LNode));
        if (!q) {
            exit(OVERFLOW);
        }
        q->data = e;
        q->next = p->next;
        p->next = q;
        return OK;
    }
    return ERROR;
}

Status ListDelete_L(LinkList L, int i, LElemType_L *e)
{
    LinkList p;
    int count = 1;
    p = L;
    while (p && count < i) {
        p = p->next;
        ++count;
    }
    if (p && p->next) {
        *e = p->next->data;
        p->next = p->next->next;
        return OK;
    }
    return ERROR;
}

Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L))
{
    LinkList p;
    if (!L) {
        return ERROR;
    }
    p = L->next;
    while (p) {
        Visit(p->data);
        p = p->next;
    }
    return OK;
}

Status CreateList_HL(FILE *fp, LinkList *L, int n)
{
    LinkList p;
    LElemType_L e;
    *L = (LinkList)malloc(sizeof(LNode));
    if (!*L) {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
    while (n--) {
        if (Scanf(fp, "%d", &e) == 1) {
            p = (LinkList)malloc(sizeof(LNode));
            if (!p) {
                exit(OVERFLOW);
            }
            p->data = e;
            p->next = (*L)->next;
            (*L)->next = p;
        }
    }
    return OK;
}

Status CreateList_TL(FILE *fp, LinkList *L, int n)
{
    LinkList p, q;
    LElemType_L e;
    *L = (LinkList)malloc(sizeof(LNode));
    if (!(*L)) {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
    q = *L;
    while (n--) {
        if (Scanf(fp, "%d", &e) == 1) {
            p = (LinkList)malloc(sizeof(LNode));
            if (!p) {
                exit(OVERFLOW);
            }
            p->data = e;
            q->next = p;
            q = p;
        } else {
            return ERROR;
        }
    }
    q->next = NULL;
    return OK;
}

#endif