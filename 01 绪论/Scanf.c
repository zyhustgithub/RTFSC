#ifndef SCANF_C
#define SCANF_C

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

int Scanf(FILE *fp, char *format, ...)
{
    int *i;
    char *ch, *s;
    float *f;
    va_list ap;
    int fmtLen, count, k, tmp, n;

    fmtLen = strlen(format);
    va_start(ap, format);

    for (count = 0, k = 2; k <= fmtLen; k = k + 2) {
        while ((tmp = getc(fp)) != EOF) {
            if (0 < tmp && tmp < 127) {
                ungetc(tmp, fp);
                break;
            }
        }
        if (tmp == EOF) {
            break;
        }

        /* 字符 */
        if (format[k - 1] == 'c') {
            ch = va_arg(ap, char *);
            if (tmp != EOF) {
                count += fscanf(fp, "%c", ch);
            }
        }
        /* 整数 */
        if (format[k - 1] == 'd') {
            i = va_arg(ap, int *);
            while ((tmp = getc(fp)) != EOF) {
                if ((tmp >= '0' && tmp <= '9') || tmp == '-' || tmp == '+') {
                    ungetc(tmp, fp);
                    break;
                }
            }
            if (tmp != EOF) {
                count += fscanf(fp, "%d", i);
            }
        }
        /* 浮点数 */
        if (format[k - 1] == 'f') {
            f = va_arg(ap, float *);
            while ((tmp = getc(fp)) != EOF) {
                if ((tmp >= '0' && tmp <= '9') || tmp == '-' || tmp == '+' || tmp == '.'){
                    ungetc(tmp, fp);
                    break;
                }
            }
            if (tmp != EOF) {
                count += fscanf(fp, "%f", f);
            }
        }
        /* 字符串 */
        if (format[k - 1] == 's') {
            s = va_arg(ap, char *);
            while (((tmp = getc(fp)) != EOF) && (!isprint(tmp) || tmp == ' '))
                ;
            if (!feof(fp)) {
                ungetc(tmp, fp);
                n = 0;
                while ((tmp = getc(fp)) != EOF) {
                    if (isprint(tmp) && tmp != ' ') {
                        s[n++] = tmp;
                    } else {
                        break;
                    }
                }
                ungetc(tmp, fp);
                s[n] = '\0';
                count++;
            }
        }
    }
    va_end(ap);
    return count;
}

#endif
