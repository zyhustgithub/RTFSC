#ifndef BINARYTREE_C
#define BINARYTREE_C

#include "BinaryTree.h"

Status CreateBiTree(FILE *fp, BiTree *T)
{
    TElemType e = 0;
    Scanf(fp, "%c", &e);
    if (e == '^') {
        *T = NULL;
    } else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!(*T)) {
            exit(OVERFLOW);
        }
        (*T)->data = e;
        CreateBiTree(fp, &((*T)->lchild));
        CreateBiTree(fp, &((*T)->rchild));
    }
    return OK;
}

int BiTreeLength(BiTree T)
{
    Node Queue[100];
    int maxLen = 0;
    int i = 0;
    Queue[i].lchild = T->lchild;
    Queue[i].rchild = T->rchild;
    Queue[i].Num = 1;
    while (i >= 0) {
        if (Queue[i].lchild) {
            Queue[i + 1].lchild = Queue[i].lchild;
            Queue[i + 1].rchild = Queue[i].rchild;
            Queue[i + 1].Num = 2 * Queue[i].Num;
            Queue[i].lchild = NULL;
            ++i;
            maxLen = (maxLen < Queue[i].Num) ? Queue[i].Num : maxLen;
        }
        if (Queue[i].rchild) {
            Queue[i + 1].lchild = Queue[i].lchild;
            Queue[i + 1].rchild = Queue[i].rchild;
            Queue[i + 1].Num = 2 * Queue[i].Num + 1;
            Queue[i].rchild = NULL;
            ++i;
            maxLen = (maxLen < Queue[i].Num) ? Queue[i].Num : maxLen;
        }
        while(Queue[i].lchild == NULL && Queue[i].rchild == NULL) {
            --i;
        }
    }
    return maxLen;
}

int BiTreeDepth(BiTree T)
{
    int LD = 0, RD = 0;
    if (T == NULL) {
        return 0;
    } else {
        LD = BiTreeDepth(T->lchild);
        RD = BiTreeDepth(T->rchild);
        return LD > RD ? (LD + 1) : (RD + 1);
    }
}

TElemType Parent(BiTree T, TElemType e)
{
    BiTree Queue[100] = {0};
    int i = 0;
    if (T == NULL || T->data == e) {
        return 0;
    }
    Queue[i] = T;
    while(i >= 0) {
        while (Queue[i]->lchild) {
            Queue[i + 1] = Queue[i]->lchild;
            if (Queue[i + 1]->data == e) {
                return Queue[i]->data;
            }
            Queue[i]->lchild = NULL;
            ++i;
        }
        if (Queue[i]->rchild) {
            Queue[i + 1] = Queue[i]->rchild;
            if (Queue[i + 1]->data == e) {
                return Queue[i]->data;
            }
            Queue[i]->rchild = NULL;
            ++i;
        }
        while (Queue[i]->lchild == NULL && Queue[i]->rchild == NULL) {
            --i;
        }
    }
    return 0;
}

#endif