#ifndef SEQBINARYTREE_C
#define SEQBINARYTREE_C

#include <math.h>
#include "SeqBinaryTree.h"

Status CreateBiTree_Pre_Sq(FILE *fp, SqBiTree T, int pos)
{
    char ch;
    if (Scanf(fp, "%c", ch) != 1) {
        return ERROR;
    }
    if (ch == '^') {
        T[pos] = 0;
    } else {
        T[pos] = ch;
        CreateBiTree_Pre_Sq(fp, T, 2 * pos + 1);
        CreateBiTree_Pre_Sq(fp, T, 2 * pos + 2);
    }
    return OK;
}

TElemType_Sq Value_Sq(SqBiTree T, Position pos)
{
    return T[((int)pow(2, pos.level - 1) - 1 + pos.order) - 1];
}

Status Assign_Sq(SqBiTree T, Position pos, TElemType_Sq e)
{
    int index = ((int)pow(2, pos.level - 1) - 1 + pos.order) - 1;
    if ((e == 0) && ((T[2 * index + 1] != 0) || (T[2 * index + 2] != 0))) {
        return ERROR;
    } else if (T[(index - 1) / 2] == 0) {
        return ERROR;
    } else {
        T[index] = e;
    }
    return OK;
}

TElemType_Sq LeftSibling_Sq(SqBiTree T, TElemType_Sq e)
{
    if (BiTreeLength_Sq(T)) {
        for (int i = 2; i < BiTreeLength_Sq(T); i += 2) {
            if (T[i] == e) {
                return T[i - 1];
            }
        }
    }
    return 0;
}

// pos 从0开始计
void PreOrderTraverse_Sq(SqBiTree T, void(Visit)(TElemType_Sq), int pos)
{
    if (T[pos] != 0) {
        Visit(T[pos]);
        PreOrderTraverse_Sq(T, Visit, 2 * pos + 1);
        PreOrderTraverse_Sq(T, Visit, 2 * pos + 2);
    }
}

void Print_Sq(SqBiTree T)
{
    TElemType_Sq tmpMatrix[MAX_TREE_SIZE][MAX_TREE_SIZE] = {0};
    int level = BiTreeDepth_Sq(T);
    for (int i = 1; i <= level; ++i) {
        for (int j = 1; j <= (int)pow(2, level - 1); ++j) {
            tmpMatrix[i - 1][j - 1] =
                T[((int)pow(2, level - i) - 1) + (j - 1) * (int)pow(2, level - i + 1) - 1];
        }
    }
    for (int i = 0; i < level; ++i) {
        for (int j = 0; j < (int)pow(2, level) - 1; ++j) {
            TElemType_Sq tmpCh = tmpMatrix[i][j];
            if (tmpCh) {
                printf("%c ", tmpCh);
            } else {
                printf("  ");
            }
        }
        putchat('\n');
    }
}

#endif