#ifndef TRI_BINARYTREE_C
#define TRI_BINARYTREE_C

#include "Tri_BinaryTree.h"

void Create_Tri(TBiTree *T, FILE *fp)
{
    TElemType_Tri tmpChar;
    Scanf(fp, "%c", &tmpChar);
    if (tmpChar == '^') {
        *T = NULL;
    } else {
        *T = (TBiTree)malloc(sizeof(TBiTNode));
        (*T)->data = tmpChar;
        Create_Tri(&((*T)->lchild), fp);
        Create_Tri(&((*T)->rchild), fp);
    }
}

Status CreateBiTree_Tri(FILE *fp, TBiTree *T)
{
    LinkQueue Q;
    QElemType_L e;
    Create_Tri(T, fp);

    if (*T == NULL) {
        return ERROR;
    }
    (*T)->parent = NULL;

    InitQueue_L(&Q);
    EnQueue_L(&Q, *T);

    while (!QueueEmpty_L(Q)) {
        DeQueue_L(&Q, &e);
        if (e->lchild) {
            e->lchild->parent = e;
            EnQueue_L(&Q, e->lchild);
        }
        if (e->rchild) {
            e->rchild->parent = e;
            EnQueue_L(&Q, e->rchild);
        }
    }
    return OK;
}

int BiTreeLength_Tri(TBiTree T)
{
    LinkQueue Q;
    QElemType_L e;
    int num[100] = {0};
    int i = 0;
    int j = 0;

    if (T == NULL) {
        return 0;
    }
    
    num[j++] = 1;
    InitQueue_L(&Q);
    EnQueue_L(&Q, T);
    while (!QueueEmpty_L(Q)) {
        DeQueue_L(&Q, &e);
        if (e->lchild) {
            num[j++] = 2 * num[i];
            EnQueue_L(&Q, e->lchild);
        }
        if (e->rchild) {
            num[j++] = 2 * num[i] + 1;
            EnQueue_L(&Q, e->rchild);
        }
        ++i;
    }
    return num[j - 1];
}

int BiTreeDepth_Tri(TBiTree T)
{
    if (BiTreeLength_Tri(T)) {
        return log(BiTreeLength_Tri(T)) / log(2) + 1;
    }
    return 0;
}

TBiTree Position_Tri(TBiTree T, TElemType_Tri e)
{
    LinkQueue Q;
    QElemType_L elem;
    TBiTree retPtr = NULL;
    if (T == NULL) {
        return NULL;
    }
    InitQueue_L(&Q);
    EnQueue_L(&Q, T);
    while (!QueueEmpty_L(Q)) {
        DeQueue_L(&Q, &elem);
        if (elem->data == e) {
            retPtr = elem;
            break;
        }
        if (elem->lchild) {
            EnQueue_L(&Q, elem->lchild);
        }
        if (elem->rchild) {
            EnQueue_L(&Q, elem->rchild);
        }
    }
    DestroyQueue_L(&Q);
    return retPtr;
}

void PrintTree_Tri(TBiTree T)
{
    // Continue...
}

#endif