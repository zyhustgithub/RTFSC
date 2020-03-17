#include "BinaryTree.c"

int main(int argc, char *argv[])
{
    BiTree T = NULL;
    FILE *fp = fopen("TestData.txt", "r");
    CreateBiTree(fp, &T);
    // char res = LeftChild(T, 'J');
    // char res = Traverse_InOrderLR(T);
    char res = Traverse_PostOrderLR(T);
    putchar('\n');
    // printf("%c\n", res);
    PrintTree(T);
    return 0;
}