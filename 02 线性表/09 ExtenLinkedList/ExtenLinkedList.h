#ifndef EXTENLINKEDLIST_H
#define EXTENLINKEDLIST_H

#include <stdlib.h>
#include "../../01 绪论/Status.h"

#ifndef POLYNOMIAL_H
typedef int LElemType_E;
#endif

typedef struct ELNode
{
    LElemType_E data;
    struct ELNode *next;
} ELNode;

typedef ELNode *Link;
typedef ELNode *PositionPtr;
typedef struct
{
    Link head, tail;
    int len;
} ELinkList;

/* 创建节点 */
Status MakeNode_E(Link *p, LElemType_E e);

/* 释放节点 */
void FreeNode_E(Link *p);

/* 初始化 */
Status InitList_E(ELinkList *L);

/* 清空 */
void ClearList_E(ELinkList *L);

/* 销毁 */
void DestroyList_E(ELinkList *L);

/* p所指节点后插入s所指节点 */
void InsFirst_E(ELinkList *L, Link p, Link s);

/* 删除p所指节点，并将节点地址保存至*q地址 */
Status DelFirst_E(ELinkList *L, Link p, Link *q);

/* 添加尾节点 */
void Append_E(ELinkList *L, Link s);

/* 删除尾节点 */
Status Remove_E(ELinkList *L, Link *q);

/* 前插并将*p指向新插入节点 */
void InsBefore(ELinkList *L, Link *p, Link s);

/* 后插并将*p指向新插入节点 */
void InsAfter(ELinkList *L, Link *p, Link s);

/* 设置节点数据 */
void SetCurElem_E(Link p, LElemType_E e);

/* 获取节点数据 */
LElemType_E GetCurElem_E(Link p);

/* 是否为空 */
Status ListEmpty_E(ELinkList L);

/* 长度 */
int ListLength_E(ELinkList L);

/* 头指针 */
PositionPtr GerHead_E(ELinkList L);

/* 尾指针 */
PositionPtr GetLast_E(ELinkList L);

/* 前驱指针 */
PositionPtr PriorPos_E(ELinkList L, Link p);

/* 后驱指针 */
PositionPtr NextPos_E(Link p);

/* 返回指定指针 */
Status LocatePos_E(ELinkList L, int i, Link *p); 

/* 返回第一个满足条件的指针 */
PositionPtr LocateElem_E(ELinkList L, LElemType_E e, Status(compare)(LElemType_E, LElemType_E));

/* 遍历操作 */
Status ListTraverse_E(ELinkList L, void(Visit)(LElemType_E e));

/* 插入值 */
Status ListInsert_L_E(ELinkList *L, int i, LElemType_E e);

/* 删除值 */
Status ListDelete_L_E(ELinkList *L, int i, LElemType_E *e );

#endif
