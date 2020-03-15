#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "../../01 绪论/Status.h"
#include "../../01 绪论/Scanf.c"

typedef char TElemType;
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode;
typedef BiTNode *BiTree;

typedef BiTree SElemType_Sq;
#include "../../03 栈和队列/01 SequenceStack/SequenceStack.h"

typedef struct {
    BiTree lchild;
    BiTree rchild;
    int Num;
} Node;

// 初始化
void InitBiTree(BiTree *T);
// 清空
void ClearBiTree(BiTree *T);
// 销毁
void DestroyBiTree(BiTree *T);
// 是否为空
Status BiTreeEmpty(BiTree T);
// 创建二叉树
Status CreateBiTree(FILE *fp, BiTree *T);
// 二叉树长度
int BiTreeLength(BiTree T);
// 二叉树深度
int BiTreeDepth(BiTree T);
// 获取根结点
Status Root(BiTree T, TElemType *e);
// 获取节点值
TElemType Value(BiTree p);
// 设置节点值
void Assign(BiTree p, TElemType e);
// 父节点
TElemType Parent(BiTree T, TElemType e);
// 左孩子
TElemType LeftChild(BiTree T, TElemType e);
// 右孩子
TElemType RightChild(BiTree T, TElemType e);
// 左兄弟
TElemType LeftSibling(BiTree T, TElemType e);
// 获取指定元素指针
BiTree LocationBiTree_1(BiTree T, TElemType e);
BiTree LocationBiTree_2(BiTree T, TElemType e);
// 插入子树
Status InsertBiTree(BiTree T, TElemType e, BiTree Q, int LR);
// 删除子树
Status DeleteBiTree(BiTree T, TElemType e, int LR);
// 层序遍历
void LevelOrderTraverse(BiTree T, void(Visit)(TElemType));
// 前序遍历
void PreOrderTraverse_1(BiTree T, void(Visit)(TElemType));
Status PreOrderTraverse_2(BiTree T, Status(Visit)(TElemType));
// 中序遍历
void InOrderTraverse_1(BiTree T, void(Visit)(TElemType));
Status InOrderTraverse_2(BiTree T, Status(Visit)(TElemType));
Status InOrderTraverse_3(BiTree T, Status(Visit)(TElemType));
// 后序遍历
void PostOrderTraverse(BiTree T, void(Visit)(TElemType));
// 结构打印二叉树
void PrintTree(BiTree T);

#endif
