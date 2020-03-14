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
    BiTNode Queue[100] = {0};
    int i = 0;
    if (T == NULL || T->data == e) {
        return 0;
    }
    Queue[i] = *T;
    while(i >= 0) {
        while (Queue[i].lchild) {
            if (Queue[i].lchild->data == e) {
                return Queue[i].data;
            }
            Queue[i + 1] = *Queue[i].lchild;
            Queue[i].lchild = NULL;
            ++i;
        }
        if (Queue[i].rchild) {
            if (Queue[i].rchild->data == e) {
                return Queue[i].data;
            }
            Queue[i] = *Queue[i].rchild;  // i节点位置无效，不再需要
            ++i;
        }
        while (Queue[i].lchild == NULL && Queue[i].rchild == NULL) {
            --i;
        }
    }
    return 0;
}

// 先序前继遍历：父节点->左孩子->右孩子
TElemType LeftChild(BiTree T, TElemType e)
{
    BiTNode Queue[100] = {0};
    int i = 0;
    if (T == NULL) {
        return ERROR;
    }
    Queue[i] = *T;
    printf("%c", Queue[i].data);
    while (i >= 0) {
        while (Queue[i].lchild) {
            if (Queue[i].data == e) {
                return Queue[i].lchild->data;
            }
            Queue[i + 1] = *Queue[i].lchild;
            Queue[i].lchild = NULL;
            ++i;
            printf("%c", Queue[i].data);
        }
        if (Queue[i].data == e) {
            return 0;
        }
        if (Queue[i].rchild) {
            Queue[i] = *Queue[i].rchild;
            printf("%c", Queue[i].data);
        } else {
            --i;
        }
        while ((Queue[i].lchild == NULL) && (Queue[i].rchild == NULL) && (Queue[i].data != e)) {
            --i;
        }
    }
    return 0;
}

// 中序前继遍历：左孩子->父节点->右孩子
Status Traverse_InOrderLR(BiTree T)
{
    BiTNode Queue[100] = {0};
    int i = 0;
    if (T == NULL) {
        return ERROR;
    }
    Queue[i] = *T;
    while (i >= 0) {
        while (Queue[i].lchild) {
            Queue[i + 1] = *Queue[i].lchild;
            Queue[i].lchild = NULL;
            ++i;
        }
        printf("%c", Queue[i].data);
        if (Queue[i].rchild) {
            Queue[i] = *Queue[i].rchild;
        } else {
            --i;
        }
        while ((Queue[i].lchild == NULL) && (Queue[i].rchild == NULL)) {
            printf("%c", Queue[i].data);
            --i;
        }
    }
    return OK;
}

// 后序前继遍历：左孩子->右孩子->父节点
Status Traverse_PostOrderLR(BiTree T)
{
    BiTNode Queue[100] = {0};
    int i = 0;
    if (T == NULL) {
        return ERROR;
    }
    Queue[i] = *T;
    while (i >= 0) {
        while (Queue[i].lchild) {
            Queue[i + 1] = *Queue[i].lchild;
            Queue[i].lchild = NULL;
            ++i;
        }
        if (Queue[i].rchild) {
            Queue[i + 1] = *Queue[i].rchild;
            Queue[i].rchild = NULL;
            ++i;
        }
        while ((Queue[i].lchild == NULL) && (Queue[i].rchild == NULL)) {
            printf("%c", Queue[i].data);
            --i;
        }
    }
    return 0;
}

// 先序后继遍历：父节点->右孩子->左孩子
TElemType RightChild(BiTree T, TElemType e)
{
    BiTNode Queue[100] = {0};
    int i = 0;
    if (T == NULL) {
        return 0;
    }
    Queue[i] = *T;
    while (i >= 0) {
        while (Queue[i].rchild) {
            if (Queue[i].data == e) {
                return Queue[i].rchild->data;
            }
            Queue[i + 1] = *Queue[i].rchild;
            Queue[i].rchild = NULL;
            ++i;
        }
        if (Queue[i].data == e) {
            return 0;
        }
        if (Queue[i].lchild) {
            Queue[i] = *Queue[i].lchild;
        } else {
            --i;
        }
        while ((Queue[i].lchild == NULL) && (Queue[i].rchild == NULL) && (Queue[i].data != e)) {
            --i;
        }
    }
    return 0;
}

TElemType LeftSibling(BiTree T, TElemType e)
{
    BiTNode Queue[100] = {0};
    int i = 0;
    if ((T == NULL) || (T->data == e)) {
        return 0;
    }
    Queue[i] = *T;
    while (i >= 0) {
        while (Queue[i].lchild) {
            if ((Queue[i].rchild) && (Queue[i].rchild->data == e)) {
                return Queue[i].lchild->data;
            }
            if (Queue[i].lchild->data == e) {
                return 0;
            }
            Queue[i + 1] = *Queue[i].lchild;
            Queue[i].lchild = NULL;
            ++i;
        }
        if (Queue[i].rchild) {
            Queue[i] = *Queue[i].rchild;
            if (Queue[i].data == e) {
                return 0;
            }
        } else {
            --i;
        }
        while ((Queue[i].lchild == NULL) && (Queue[i].rchild == NULL)) {
            --i;
        }
    }
    return 0;
}

TElemType RightSibling(BiTree T, TElemType e)
{
    BiTNode Queue[100] = {0};
    int i = 0;
    if ((T == NULL) || (T->data == e)) {
        return 0;
    }
    Queue[i] = *T;
    while (i >= 0) {
        while (Queue[i].lchild) {
            if (Queue[i].lchild->data == e) {
                if (Queue[i].rchild) {
                    return Queue[i].rchild->data;
                } else {
                    return 0;
                }
            }
            Queue[i + 1] = *Queue[i].lchild;
            Queue[i].lchild = NULL;
            ++i;
        }
        if (Queue[i].rchild) {
            Queue[i] = *Queue[i].rchild;
            if (Queue[i].data == e) {
                return 0;
            }
        } else {
            --i;
        }
        while ((Queue[i].lchild == NULL) && (Queue[i].rchild == NULL)) {
            --i;
        }
    }
    return 0;
}

BiTree LocationBiTree_1(BiTree T, TElemType e)
{
    BiTNode Queue[100] = {0};
    int i = 0;
    if ((T == NULL) || (T->data == e)) {
        return T;
    }
    Queue[i] = *T;
    while (i >= 0) {
        while (Queue[i].lchild) {
            if (Queue[i].lchild->data == e) {
                return Queue[i].lchild;
            }
            Queue[i + 1] = *Queue[i].lchild;
            Queue[i].lchild = NULL;
            ++i;
        }
        if (Queue[i].rchild) {
            if (Queue[i].rchild->data == e) {
                return Queue[i].rchild;
            }
            Queue[i] = *Queue[i].rchild;
        } else {
            --i;
        }
        while ((Queue[i].lchild == NULL) && (Queue[i].rchild == NULL)) {
            --i;
        }
    }
    return NULL;
}

BiTree LocationBiTree_2(BiTree T, TElemType e)
{
    BiTree p = NULL;
    if ((T == NULL) || (T->data == e)) {
        return T;
    } else {
        if ((p = LocationBiTree_2(T->lchild, e))) {
            return p;
        }
        if ((p = LocationBiTree_2(T->rchild, e))) {
            return p;
        }
        return p;
    }
}

#endif
