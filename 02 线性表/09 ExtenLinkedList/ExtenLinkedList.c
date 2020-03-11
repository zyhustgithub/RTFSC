#ifndef EXTENLINKEDLIST_C
#define EXTENLINKEDLIST_C

#include "ExtenLinkedList.h"

Status MakeNode_E(Link *p, LElemType_E e)
{
    *p = (Link)malloc(sizeof(ELNode));
    if (!(*p)) {
        exit(OVERFLOW);
    }
    (*p)->data = e;
    (*p)->next = NULL;
    return OK;
}

void FreeNode_E(Link *p)
{
    free(*p);
    *p = NULL;
}

Status InitList_E(ELinkList *L)
{
    L->head = L->tail = (Link)malloc(sizeof(ELNode));
    if (!L->head) {
        exit(OVERFLOW);
    }
    L->head->next = NULL;
    L->len = 0;
    return OK;
}

void ClearList_E(ELinkList *L)
{
    Link p = L->head->next;
    while (p) {
        L->head->next = p->next;
        free(p);
        p = L->head->next;
    }
    L->tail = L->head;
    L->len = 0;
}

void DestroyList_E(ELinkList *L)
{
    ClearList_E(L);
    free(L->head);
    L->head = L->tail = NULL;
}

void InsFirst_E(ELinkList *L, Link p, Link s)
{
    s->next = p->next;
    p->next = s;
    if (p == L->tail) {
        L->tail = s;
    }
    ++L->len;
}

Status DelFirst_E(ELinkList *L, Link p, Link *q)
{
    if (!p->next) {
        return ERROR;
    }
    *q = p->next;
    if (p->next == L->tail) {
        L->tail = p;
    }
    p->next = p->next->next;
    --L->len;
    return OK;
}

void Append_E(ELinkList *L, Link s)
{
    L->tail->next = s;
    while (s) {
        L->tail = s;
        ++L->len;
        s = s->next;
    }
}

Status Remove_E(ELinkList *L, Link *q)
{
    if (!L || L->len == 0) {
        return ERROR;
    }
    *q = L->tail;
    L->tail = L->head;
    while (L->tail->next != *q) {
        L->tail = L->tail->next;
    }
    L->tail->next = NULL;
    --L->len;
    return OK;
}

void InsBefore(ELinkList *L, Link *p, Link s)
{
    Link tmp;
    tmp = PriorPos_E(*L, *p);
    tmp->next = s;
    s->next = *p;
    *p = s;
    if (tmp == L->tail) {
        L->tail = s;
    }
    ++L->len;
}

void InsAfter(ELinkList *L, Link *p, Link s)
{
    s->next = (*p)->next;
    (*p)->next = s;
    if (*p == L->tail) {
        L->tail = s;
    }
    *p = s;
    ++L->len;
}

void SetCurElem_E(Link p, LElemType_E e)
{
    p->data = e;
}

LElemType_E GetCurElem_E(Link p)
{
    return p->data;
}

Status ListEmpty_E(ELinkList L)
{
    return (L.len == 0 ? TRUE : FALSE);
}

int ListLength_E(ELinkList L)
{
    return L.len;
}

PositionPtr GetHead_E(ELinkList L)
{
    return L.head;
}

PositionPtr GetLast_E(ELinkList L)
{
    return L.tail;
}

PositionPtr PriorPos_E(ELinkList L, Link p)
{
    Link tmp = L.head;
    while (tmp->next && tmp->next != p) {
        tmp = tmp->next;
    }
    if (tmp->next) {
        return tmp;
    }
    return NULL;
}

PositionPtr NextPos_E(Link p)
{
    return p->next;
}

Status LocatePos_E(ELinkList L, int i, Link *p)
{
    if (i < 0 || i > L.len) {
        return ERROR;
    }
    Link tmp = L.head;
    int count = 0;
    while (tmp && count < i) {
        tmp = tmp->next;
        ++count;
    }
    if (tmp) {
        *p = tmp;
        return OK;
    }
    return ERROR;
}

PositionPtr LocateElem_E(ELinkList L, LElemType_E e, Status(compare)(LElemType_E, LElemType_E))
{
    if (L.len) {
        Link tmp = L.head->next;
        while (tmp && !compare(e, tmp->data)) {
            tmp = tmp->next;
        }
        if (tmp) {
            return tmp;
        }
    }
    return NULL;
}

Status ListInsert_L_E(ELinkList *L, int i, LElemType_E e)
{
    Link tmp;
    Link s;
    if (!LocatePos_E(*L, i - 1, &tmp)) {
        return ERROR;
    }
    MakeNode_E(&s, e);
    s->next = tmp->next;
    tmp->next = s;
    ++L->len;
    if (L->tail == tmp) {
        L->tail = s;
    }
    return OK;
}

Status ListDelete_L_E(ELinkList *L, int i, LElemType_E *e)
{
    Link tmp;
    if (!LocatePos_E(*L, i - 1, &tmp)) {
        return ERROR;
    }
    if (tmp->next) {
        *e = tmp->next->data;
        if (tmp->next == L->tail) {
            L->tail = tmp;
        }
        tmp->next = tmp->next->next;
        --L->len;
        free(tmp->next);
        return OK;
    }
    return ERROR;
}

Status ListTraverse_E(ELinkList L, void(Visit)(LElemType_E))
{
    if (L.len == 0) {
        return ERROR;
    }
    Link tmp = L.head->next;
    while (tmp) {
        Visit(tmp->data);
        tmp = tmp->next;
    }
    return OK;
}

#endif