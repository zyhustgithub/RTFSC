#ifndef MERGEELIST_H
#define MERGEELIST_H

#include <stdio.h>
#include "../../01 绪论/Scanf.c"
#include "../09 ExtenLinkedList/ExtenLinkedList.c"

/* 合并 */
Status MergeEList_L(ELinkList La, ELinkList Lb, ELinkList *Lc, int(compare)(LElemType_E, LElemType_E));

/* 比较大小 */
int Cmp(LElemType_E e1, LElemType_E e2);

/* 构造链表 */
Status CreateList_ascend(FILE *fp, ELinkList *L, int n);

#endif