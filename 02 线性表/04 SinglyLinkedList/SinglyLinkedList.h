#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdlib.h>
#include "../../01 绪论/Status.h"
#include "../../01 绪论/Scanf.c"

#ifndef BANKQUEUING_H
typedef int LElemType_L;

typedef struct LNode {
    LElemType_L data;
    struct LNode *next;
} LNode;

typedef LNode *LinkList;
#endif

/* 初始化 */
Status InitList_L(LinkList *L);

/* 清空 */
Status ClearList_L(LinkList L);

/* 销毁 */
void DestroyList_L(LinkList *L);

/* 是否为空 */
Status ListEmpty_L(LinkList L);

/* 元素个数 */
int ListLength_L(LinkList L);

/* 获取指定位置元素的值 */
Status GetElem_L(LinkList L, int i, LElemType_L *e);

/* 获取指定值的元素位置 */
int LocateElem_L(LinkList L, LElemType_L cur_e, Status(compare)(LElemType_L, LElemType_L));

/* 前驱 */
Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *prior_e);

/* 后驱 */
Status NextElem_L(LinkList L, LElemType_L cur_r, LElemType_L *next_e);

/* 插入 */
Status ListInsert_L(LinkList L, int i, LElemType_L e);

/* 删除 */
Status ListDelete_L(LinkList L, int i, LElemType_L *e);

/* 遍历 */
Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L));

/* 逆序构造 */
Status CreateList_HL(FILE *fp, LinkList *L, int n);

/* 顺序构造 */
Status CreateList_TL(FILE *fp, LinkList *L, int n);

#endif