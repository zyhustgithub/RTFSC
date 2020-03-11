#ifndef STATICLINKEDLIST_H
#define STATICLINKEDLIST_H

#include <stdlib.h>
#include "../../01 绪论/Status.h"

#define MAXSIZE 1000

typedef int SLinkList;
typedef int LElemType_S;
typedef struct
{
    LElemType_S data;
    int cur;
} Component[MAXSIZE];

Component SPACE;

/* 初始化 */
void InitSpace_SL();

/* 分配资源 */
int Malloc_SL();

/* 释放资源 */
void Free_SL(int k);

/* 初始化 */
Status InitList_SL(SLinkList *H);

/* 清空 */
Status ClearList_SL(SLinkList H);

/* 销毁 */
void DestroyList_SL(SLinkList *H);

/* 是否为空 */
Status ListEmpty_SL(SLinkList H);

/* 元素个数 */
int ListLength_SL(SLinkList H);

/* 获取指定位置的元素值 */
Status GetElem_SL(SLinkList H, int i, LElemType_S *e);

/* 获取指定值的元素位置 */
int LocateElem_SL(SLinkList H, LElemType_S e);

/* 前驱 */
Status PriorElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *pre_e);

/* 后驱 */
Status NextElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *next_e);

/* 插入 */
Status ListInsert_SL(SLinkList H, int i, LElemType_S e);

/* 删除 */
Status ListDelete_SL(SLinkList H, int i, LElemType_S *e);

/* 遍历 */
Status ListTraverse_SL(SLinkList H, void(Visit)(LElemType_S));

#endif
