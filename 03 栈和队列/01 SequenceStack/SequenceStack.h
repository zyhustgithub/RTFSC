#ifndef SEQUENCESTACK_H
#define SEQUENCESTACK_H

#include <stdio.h>
#include <stdlib.h>
#include "../../01 绪论/Status.h"

#if !defined MAZE_H             && \
    !defined EXPRESSION_H       && \
    !defined BINARYTREE_H       && \
    !defined CHILDSIBLINGTREE_H && \
    !defined Question_8
typedef int SElemType_Sq;
#endif

typedef struct {
    SElemType_Sq *base;
    SElemType_Sq *top;
    int stacksize;
} SqStack;

// 初始化栈
void InitStack_Sq(SqStack *S);
// 清空栈
void ClearStack_Sq(SqStack *S);
// 销毁栈
void DestroyStack_Sq(SqStack *S);
// 是否为空
Status StackEmpty_Sq(SqStack S);
// 栈的长度
int StackLength_Sq(SqStack S);
// 获取栈顶元素
Status GetTop_Sq(SqStack S, SElemType_Sq *e);
// 入栈
Status Push_Sq(SqStack *S, SElemType_Sq e);
// 出栈
Status Pop_Sq(SqStack *S, SElemType_Sq *e);
// 遍历
Status StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq));

#endif
