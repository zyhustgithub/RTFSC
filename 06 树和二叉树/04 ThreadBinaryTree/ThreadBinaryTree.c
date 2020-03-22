#ifndef THREADBINARYTREE_C
#define THREADBINARYTREE_C

#include "ThreadBinaryTree.h"

Status CreateBiTree_Thr(FILE *fp, ThrBiTree *T)
{
    TElemType_Thr tmpChar;
    if (!Scanf(fp, "%c", &tmpChar)) {
        return ERROR;
    }
    if (tmpChar == '^') {
        *T = NULL;
    } else {
        *T = (ThrBiTree)malloc(sizeof(ThrBiTNode));
        if (!*T) {
            exit(OVERFLOW);
        }
        (*T)->data = tmpChar;
        CreateBiTree_Thr(fp, &((*T)->lchild));
        if ((*T)->lchild) {
            (*T)->LTag = Link;
            (*T)->lchild->parent = *T;
        } else {
            (*T)->LTag = Thread;
        }

        CreateBiTree_Thr(fp, &((*T)->rchild));
        if ((*T)->rchild) {
            (*T)->RTag = Link;
            (*T)->rchild->parent = *T;
        } else {
            (*T)->RTag = Thread;
        }
    }
    return OK;
}

void InThreading_Thr(ThrBiTree p)
{
    if (p != NULL) {
        if (p->lchild) {
            InThreading_Thr(p->lchild);
        } else {
            p->lchild = pre;
        }

        if (pre->RTag == Thread) {
            pre->rchild = p;
        }
        pre = p;

        if (p->RTag == Link) {
            InThreading_Thr(p->rchild);
        }
    }
}

Status InOrderThreading_Thr(ThrBiTree *H, ThrBiTree T)
{
    *H = (ThrBiTree)malloc(sizeof(ThrBiTNode));
    if (!*H) {
        exit(OVERFLOW);
    }
    (*H)->data = '\0';
    (*H)->parent = NULL;
    (*H)->rchild = *H;
    (*H)->RTag = Thread;
    (*H)->LTag = Link;

    if (T == NULL) {
        (*H)->lchild = *H;
    } else {
        (*H)->lchild = T;
        pre = *H;
        InThreading_Thr(T);
        pre->rchild = *H;
    }
    return OK;
}

void InOrderTraverse_Thr(ThrBiTree H, void(Visit)(TElemType_Thr))
{
    ThrBiTree p = H->lchild;
    while (p != H) {
        while (p->lchild) {
            p = p->lchild;
        }
        Visit(p->data);
        
        while (p->RTag == Thread && p != H) {
            p = p->rchild;
            Visit(p->data);
        }
        p = p->rchild;
    }
}

void PreThreading_Thr(ThrBiTree p)
{
    if (p) {
        if (pre->RTag == Thread) {
            pre->rchild = p;
        }
        pre = p;
        if (p->lchild) {
            PreThreading_Thr(p->lchild);
        }
        if (p->rchild) {
            PreThreading_Thr(p->rchild);
        }
    }
}

Status PreOrderThreading_Thr(ThrBiTree *H, ThrBiTree T)
{
    (*H) = (ThrBiTree)malloc(sizeof(ThrBiTNode));
    if ((*H) == NULL) {
        exit(OVERFLOW);
    }
    (*H)->data = '\0';
    (*H)->parent = NULL;
    (*H)->RTag = Thread;
    (*H)->rchild = *H;
    (*H)->LTag = Link;

    if (T == NULL) {
        (*H)->lchild = *H;
    } else {
        (*H)->lchild = T;
        pre = *H;
        PreThreading_Thr(T);
        pre->rchild = *H;
        (*H)->rchild = pre;
    }
    return OK;
}

void PreOrderTraverse_Thr(ThrBiTree H, void(Visit)(TElemType_Thr))
{
    ThrBiTree p = H;
    while (p->rchild != H) {
        while (p->lchild) {
            p = p->lchild;
            Visit(p->data);
        }
        if (p->rchild != H) {
            p = p->rchild;
            Visit(p->data);
        }
    }
}

void PostThreading_Thr(ThrBiTree p)
{
    if (p) {
        if (p->RTag == Thread) {
            p->rchild = pre;
        }
        pre = p;
        if (p->RTag == Link) {
            PostThreading_Thr(p->rchild);
        }
        if (p->LTag == Link) {
            PostThreading_Thr(p->lchild);
        }
    }
}

Status PostOrderThreading_Thr(ThrBiTree *H, ThrBiTree T)
{
    *H = (ThrBiTree)malloc(sizeof(ThrBiTNode));
    if (!*H) {
        exit(OVERFLOW);
    }
    (*H)->data = '\0';
    (*H)->parent = NULL;
    (*H)->RTag = Thread;
    (*H)->rchild = *H;
    (*H)->LTag = Link;

    if (T == NULL) {
        (*H)->lchild = *H;
    } else {
        (*H)->lchild = T;
        pre = *H;
        PostThreading_Thr(T);
        (*H)->rchild = T;
    }
    return OK;
}

void PostOrderTraverse_Thr(ThrBiTree H, void(Visit)(TElemType_Thr))
{
    ThrBiTree p = H->lchild;
    if (p != H) {
        while (1) {
            while(p->lchild) {
                p = p->lchild;
            }
            if (p->RTag == Link) {
                p = p->rchild;
            } else {
                break;
            }
        }
        while (p->rchild != H) {
            Visit(p->data);
            p = Pos_NextPtr_Thr(H, p);
        }
    }
}

ThrBiTree Pos_NextPtr_Thr(ThrBiTree H, ThrBiTree p)
{
    if (p == H) {
        return NULL;
    }
    if (p->RTag == Thread) {
        return p->rchild;
    } else {
        if (p == p->parent->rchild) {
            return p->parent;
        } else {
            if (!p->parent->rchild) {
                return p->parent;
            } else {
                p = p->parent->rchild;
                while (1) {
                    while (p->lchild) {
                        p = p->lchild;
                    }
                    if (p->RTag == Link) {
                        p = p->rchild;
                    } else {
                        break;
                    }
                }
                return p;
            }
        }
    }
}

#endif
