#ifndef TRI_BINARYTREE_H
#define TRI_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../01 绪论/Status.h"
#include "../../01 绪论/Scanf.c"

typedef char TElemType_Tri;
typedef struct TBiTNode {
    TElemType_Tri data;
    struct TBiTNode *parent;
    struct TBiTNode *lchild;
    struct TBiTNode *rchild;
} TBiTNode;
typedef TBiTNode *TBiTree;

typedef TBiTree QElemType_L;
#include "../../03 栈和队列/07 LinkQueue/LinkQueue.c"

void InitBiTree_Tri(TBiTree *T);

void ClearBiTree_Tri(TBiTree *T);

void DestroyBiTree_Tri(TBiTree *T);

Status BiTreeEmpty_Tri(TBiTree T);

void Create_Tri(TBiTree *T, FILE *fp);

Status CreateBiTree_Tri(FILE *fp, TBiTree *T);

int BiTreeLength_Tri(TBiTree T);

int BiTreeDepth_Tri(TBiTree T);

Status Root_Tri(TBiTree T, TElemType_Tri *e);

TElemType_Tri Value_Tri(TBiTree p);

void Assign_Tri(TBiTree p, TElemType_Tri e);

TBiTree Point_Tri(TBiTree T, TElemType_Tri e);

TElemType_Tri Parent_Tri(TBiTree T, TElemType_Tri e);

TElemType_Tri LeftChild_Tri(TBiTree T, TElemType_Tri e);

TElemType_Tri RightChild_Tri(TBiTree T, TElemType_Tri e);

TElemType_Tri LeftSibling_Tri(TBiTree T, TElemType_Tri e);

TElemType_Tri RightSibling_Tri(TBiTree T, TElemType_Tri e);

Status InsertBiTree_Tri(TBiTree T, TElemType_Tri e, TBiTree Q, int LR);

Status DeleteBiTree_Tri(TBiTree T, TElemType_Tri e, int LR);

void LevelOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri));

void PreOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri));

void InOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri));

void PostOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri));

void PrintTree_Tri(TBiTree T);

#endif
