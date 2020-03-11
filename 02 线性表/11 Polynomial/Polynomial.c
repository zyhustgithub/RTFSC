#ifndef POLYNOMIAL_C
#define POLYNOMIAL_C

#include "Polynomial.h"

Status CreatePolyn_P(FILE *fp, Polynomial *P, int n)
{
    ElemType_P e;
    if (!InitList_E(P)) {
        return ERROR;
    }
    for (int i = 1; i <= n; ++i) {
        if (Scanf(fp, "%f%d", &e.coef, &e.expn) != 2) {
            return ERROR;
        }
        ListInsert_L_E(P, i, e);
    }
    return OK;
}

void DestroyPolyn_P(Polynomial *P)
{
    DestroyList_E(P);
}

int PolynLength_P(Polynomial P)
{
    return ListLength_E(P);
}

void AddPolyn_P(Polynomial *La, Polynomial *Lb)
{
    ElemType_P e1, e2;
    Link ha, hb, pa, pb;
    float sum;
    ha = GetHead_E(*La);
    hb = GetHead_E(*Lb);
    pa = NextPos_E(ha);
    pb = NextPos_E(hb);
    while (pa && pb) {
        e1 = GetCurElem_E(pa);
        e2 = GetCurElem_E(pb);
        switch (Cmp_exp(e1, e2)) {
            case -1:
                ha = NextPos_E(ha);
                pa = NextPos_E(ha);
                break;
            case 0:
                sum = e1.coef + e2.coef;
                if (sum == 0.0) {
                    DelFirst_E(La, ha, &pa);
                    FreeNode_E(&pa);
                } else {
                    e1.coef = sum;
                    SetCurElem_E(pa, e1);
                    ha = pa;
                }
                DelFirst_E(Lb, hb, &pb);
                FreeNode_E(&pb);
                pb = NextPos_E(hb);
                pa = NextPos_E(ha);
                break;
            case 1:
                DelFirst_E(Lb, hb, &pb);
                InsFirst_E(La, ha, pb);
                pb = NextPos_E(hb);
                ha = NextPos_E(ha);
                break;
        }
    }
    if (pb) {
        Append_E(La, pb);
    }
    FreeNode_E(&hb);
    Lb->tail = Lb->head = NULL;
    Lb->len = 0;
}

void SubtractPolyn_P(Polynomial *La, Polynomial *Lb)
{
    Link ha, hb, pa, pb;
    ElemType_P e1, e2;
    float sum;
    ha = GetHead_E(*La);
    hb = GetHead_E(*Lb);
    pa = NextPos_E(ha);
    pb = NextPos_E(hb);
    while (pa && pb) {
        e1 = GetCurElem_E(pa);
        e2 = GetCurElem_E(pb);
        switch (Cmp_exp(e1, e2)) {
            case -1:
                ha = NextPos_E(ha);
                pa = NextPos_E(ha);
                break;
            case 0:
                sum = e1.coef - e2.coef;
                if (sum == 0.0) {
                    DelFirst_E(La, ha, &pa);
                    FreeNode_E(&pa);
                } else {
                    e1.coef = sum;
                    SetCurElem_E(pa, e1);
                    ha = pa;
                }
                DelFirst_E(Lb, hb, &pb);
                FreeNode_E(&pb);
                pa = NextPos_E(ha);
                pb = NextPos_E(hb);
                break;
            case 1:
                DelFirst_E(Lb, hb, &pb);
                pb->data.coef = -pb->data.coef;
                InsFirst_E(La, ha, pb);
                ha = NextPos_E(ha);
                pa = NextPos_E(ha);
                pb = NextPos_E(hb);
        }
    }
    while (pb) {
        DelFirst_E(Lb, hb, &pb);
        pb->data.coef = -pb->data.coef;
        InsFirst_E(La, ha, pb);
        ha = NextPos_E(ha);
        pb = pb->next;
    }
    FreeNode_E(&hb);
    Lb->head = Lb->tail = NULL;
    Lb->len = 0;
}

void MultiplyPolyn_P(Polynomial *La, Polynomial *Lb)
{
    Link ha, hb, pa, pb;
    Polynomial Lc, tmp;
    ElemType_P e1, e2, e;
    ha = GetHead_E(*La);
    hb = GetHead_E(*Lb);
    InitList_E(&Lc);
    while (ListLength_E(*La)) {
        DelFirst_E(La, ha, &pa);
        e1 = GetCurElem_E(pa);
        pb = NextPos_E(hb);
        InitList_E(&tmp);
        while (pb) {
            e2 = GetCurElem_E(pb);
            e.coef = e2.coef * e1.coef;
            e.expn = e2.expn + e1.expn;
            ListInsert_L_E(&tmp, tmp.len + 1, e);
            pb = pb->next;
        }
        AddPolyn_P(&Lc, &tmp);
        FreeNode_E(&pa);
    }
    AddPolyn_P(La, &Lc);
}

int Cmp_exp(ElemType_P e1, ElemType_P e2)
{
    int diff = e1.expn - e2.expn;
    if (diff < 0) {
        diff = -1; 
    } else if (diff > 0) {
        diff = 1;
    }
    return diff;
}

void PrintPolyn_P(Polynomial L)
{
    Link p = L.head->next;
    ElemType_P e;
    while (p) {
        e = GetCurElem_E(p);
        if (p == L.head->next) {
            printf("%g", e.coef);
        } else {
            if (e.coef < 0) {
                printf(" - %g", -e.coef);
            } else {
                printf(" + %g", e.coef);
            }
        }
        if (e.expn) {
            printf("x");
            if (e.expn != 1) {
                printf("^%d", e.expn);
            }
        }
        p = p->next;
    }
}

#endif