#ifndef DUALCYCLELINKEDLIST_H
#define DUALCYCLELINKEDLIST_H

#include <stdlib.h>
#include "../../01 绪论/Status.h"

typedef int LElemType_DC;
typedef struct DuLNode {
    LElemType_DC data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode;

typedef DuLNode * DuLinkList;

/* 初始化 */
Status InitList_DuL(DuLinkList *L);

/* 清空 */
Status ClearList_DuL(DuLinkList L);

/* 销毁 */
void DestroyList_DuL(DuLinkList *L);

/* 是否为空 */
Status ListEmpty_DuL(DuLinkList L);

/* 元素个数 */
int ListLength_DuL(DuLinkList L);

/* 获取指定位置的元素值 */
Status GetElem_DuL(DuLinkList L, int i, LElemType_DC *e);

/* 获取指定值的元素位置 */
int LocateElem_DuL(DuLinkList L, LElemType_DC cur_e, Status(compare)(LElemType_DC, LElemType_DC));

/* 前驱 */
Status PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *prior_e);

/* 后驱 */
Status NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *next_e);

/* 获取指向指定位置元素的指针 */
DuLinkList GetElemPtr_DuL(DuLinkList L, int i);

/* 插入 */
Status ListInsert_DuL(DuLinkList L, int i, LElemType_DC e);

/* 删除 */
Status ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e);

/* 遍历 */
Status ListTraverse_DuL(DuLinkList L, void(Visit)(LElemType_DC));

#endif