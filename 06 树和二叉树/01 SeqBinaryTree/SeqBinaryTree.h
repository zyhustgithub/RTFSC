#ifndef SEQBINARYTREE_H
#define SEQBINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "../../01 绪论/Status.h"
#include "../../01 绪论/Scanf.c"

#define MAX_TREE_SIZE 100
typedef char TElemType_Sq;
typedef TElemType_Sq SqBiTree[MAX_TREE_SIZE];
typedef struct {
    int level;
    int order;
} Position;

// 初始化二叉树
void InitBiTree_Sq(SqBiTree T);
// 清空二叉树
void ClearBiTree_Sq(SqBiTree T);
// 销毁二叉树
void DestroyBiTree_Sq(SqBiTree T);
// 二叉树是非为空
Status BiTreeEmpty_Sq(SqBiTree T);
// 层序创建二叉树
Status CreateBiTree_Le_Sq(FILE *fp, SqBiTree T);
// 先序创建二叉树
Status CreateBiTree_Pre_Sq(FILE *fp, SqBiTree T, int i);
// 二叉树长度
int BiTreeLength_Sq(SqBiTree T);
// 二叉树深度
int BiTreeDepth_Sq(SqBiTree T);
// 根结点
TElemType_Sq Root_Sq(SqBiTree T, TElemType_Sq e);
// 节点值
TElemType_Sq Value_Sq(SqBiTree T, Position pos);
// 设置节点值
Status Assign_Sq(SqBiTree T, Position pos, TElemType_Sq e);
// 父节点值
TElemType_Sq Parent_Sq(SqBiTree T, TElemType_Sq e);
// 左节点值
TElemType_Sq LeftChild_Sq(SqBiTree T, TElemType_Sq e);
// 右节点值
TElemType_Sq RightChild_Sq(SqBiTree T, TElemType_Sq e);
// 左兄弟值
TElemType_Sq LeftSibling_Sq(SqBiTree T, TElemType_Sq e);
// 右兄弟值
TElemType_Sq RightSibling_Sq(SqBiTree T, TElemType_Sq e);
// 层序遍历
void LevelTraverse_Sq(SqBiTree T);
// 先序遍历
void PreOrderTraverse_Sq(SqBiTree T, void(Visit)(TElemType_Sq), int pos);
// 中序遍历
void InOrderTraverse_Sq(SqBiTree T, void(Visit)(TElemType_Sq), int pos);
// 后序遍历
void PostOrderTraverse_Sq(SqBiTree T, void(Visit)(TElemType_Sq), int pos);
// 打印二叉树
void Print_Sq(SqBiTree T);

#endif