#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdlib.h>
#include "../../01-绪论/Status.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int LElemType_Sq;
#endif

typedef struct {
     LElemType_Sq *elem;
     int length;
     int listsize;  
} SqList; 

/* 初始化 */
Status ListInit_Sq(SqList *L);

/* 清空 */
void ClearList_Sq(SqList *L);

/* 销毁 */
void DestroyList_Sq(SqList *L);

/* 是否为空 */
Status ListEmpty_Sq(SqList L);

/* 元素个数 */
int ListLength_Sq(SqList L);

/* 获取指定位置的元素值 */
Status GetElem_Sq(SqList L, int i, LElemType_Sq *e);

/* 查询指定值的元素位置 */
int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq));

/* 前驱 */
Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *prior_e);

/* 后驱 */
Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e);

/* 插入 */
Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e);

/* 删除 */
Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e);

/* 遍历 */
Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq));

#endif