//对数组指针的理解
#include<stdio.h>
#define LISTLENGTH  10

typedef struct {
	int (*elem)[10];
	int array[10];
	int length;
	int listlength;
}SQList;

int main() {
	SQList list;
	int arr[10] = { 1,2,3 }; //定义数组
	printf("*arr: %d\n", *arr);
	printf("*(arr+1): %d\n", *(arr+1));
	int(*arrptr)[10] = &arr; //定义数组指针
	printf("**arrptr: %d\n", **arrptr);
	printf("*(* arrptr+1) :%d\n", *(* arrptr+1));
	//list.elem = arr;
	list.elem = (void *)(int *) malloc(LISTLENGTH * sizeof(int));
	(*list.elem)[0] = 11;
	*((*list.elem) + 1) = 12;

	*list.array = 21; //type arr[N]方式定义数组后，arr为常量指针，不能改变指向地址，比如：(int *)malloc(LISTLENGTH * sizeof(int));
	list.array[1] = 22;

	list.length = 2;
	list.listlength = 3;

	printf("sizeof(&list): %d\n", sizeof(&list));
	printf("sizeof(list): %d\n", sizeof(list));

	printf("list->elem: %d\n", (*((&list)->elem))[0]);
	printf("*(*(list.elem)+1): %d\n", *(*(list.elem)+1));
	printf("*list.array: %d\n", *list.array);
	printf("list.array[1]:%d\n", list.array[1]);

	printf("(&list)->length: %d\n", (&list)->length);
	printf("list.length: %d\n", list.length);
	printf("list.listlength: %d\n", list.listlength);
	return 0;
}