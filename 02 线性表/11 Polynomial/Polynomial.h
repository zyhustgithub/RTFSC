#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdio.h>
#include "../../01 绪论/Scanf.c"

typedef struct {
    float coef;
    int expn;
} LElemType_E;

#include "../09 ExtenLinkedList/ExtenLinkedList.c"

typedef ELinkList Polynomial;
typedef LElemType_E ElemType_P;

/* 构造多项式 */
Status CreatePolyn_P(FILE *fp, Polynomial *P, int n);

/* 销毁多项式 */
void DestroyPloyn_P(Polynomial *P);

/* 多项式项数 */
int PolynLength_P(Polynomial P);

/* 加法 */
void AddPolyn_P(Polynomial *La, Polynomial *Lb);

/* 减法 */
void SubtractPolyn_P(Polynomial *La, Polynomial *Lb);

/* 乘法 */
void MultiplyPolyn_P(Polynomial *La, Polynomial *Lb);

/* 幂比较 */
int Cmp_exp(ElemType_P exp1, ElemType_P exp2);

/* 打印多项式 */
void PrintPolyn_P(Polynomial P);

#endif