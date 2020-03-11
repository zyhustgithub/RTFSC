#include "Scanf.c"
#include "Status.h"

int main(int argc, char *argv[])
{
    FILE * fp = NULL;
    char buf[256] = {0};
    int count = 0;
    int num = 0;
    float fnum = 0.0;

    if (argc != 2){
        fprintf(stderr, "Usage:\n%s filename\n", argv[0]);
        return ERROR;
    }

    if ((fp = fopen(argv[1], "rb")) == NULL){
        fprintf(stderr, "Can't open file %s!\n", argv[1]);
        return ERROR;
    }

    count += Scanf(fp, "%s", buf);
    count += Scanf(fp, "%d", &num);
    count += Scanf(fp, "%f", &fnum);
    Wait(30);
    printf("count:%d->%s\n", count, buf);
    printf("count:%d->%d\n", count, num);
    printf("count:%d->%f\n", count, fnum);
    fclose(fp);
    PressEnter;

    return OK;
}
