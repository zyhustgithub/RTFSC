#ifndef STATUS_H
#define STATUS_H

#define TRUE        1
#define FALSE       0
#define YES         1
#define NO          0
#define OK          1
#define ERROR       0
#define SUCCESS     1
#define UNSUCCESS   0
#define INFEASIBLE -1

#ifndef _MATH_H_
#define OVERFLOW   -2
#define UNDERFLOW  -3
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif 

typedef int Status;

/* 暂停 */
#define Wait(x) \
{\
    double loopNum;\
    for (loopNum = 0.01; loopNum <= 100000.0 * x; loopNum += 0.01)\
        ;\
}

/* 按任意键继续 */
#define PressEnter \
{\
    fflush(stdin);\
    printf("Press any key to continue...");\
    getchar();\
    fflush(stdin);\
}

#endif
