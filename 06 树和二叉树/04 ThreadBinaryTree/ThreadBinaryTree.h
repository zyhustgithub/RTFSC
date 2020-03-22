#ifndef THREADBINARYTREE_H
#define THREADBINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "../../01 绪论/Status.h"
#include "../../01 绪论/Scanf.c"

typedef enum {Link, Thread} PointerTag;
typedef char TElemType_Thr;
typedef struct ThrBiTNode {
    TElemType_Thr data;
    struct ThrBiTNode* lchild;
    struct ThrBiTNode* rchild;
    struct ThrBiTNode* parent;
    PointerTag LTag;
    PointerTag RTag;
} ThrBiTNode;
typedef ThrBiTNode* ThrBiTree;

ThrBiTree pre;

Status CreateBiTree_Thr(FILE *fp, ThrBiTree *T);

void InThreading_Thr(ThrBiTree T);

Status InOrderThreading_Thr(ThrBiTree *H, ThrBiTree T);

void InOrderTraverse_Thr(ThrBiTree H, void(Visit)(TElemType_Thr));

void PreThreading_Thr(ThrBiTree T);

Status PreOrderThreading_Thr(ThrBiTree *H, ThrBiTree T);

void PreOrderTraverse_Thr(ThrBiTree H, void(Visit)(TElemType_Thr));

void PostThreading_Thr(ThrBiTree T);

Status PostOrderThreading_Thr(ThrBiTree *H, ThrBiTree T);

void PostOrderTraverse_Thr(ThrBiTree H, void(Visit)(TElemType_Thr));

void ParentPtr_Thr(ThrBiTree H);

ThrBiTree Pos_NextPtr_Thr(ThrBiTree H, ThrBiTree p);

#endif
