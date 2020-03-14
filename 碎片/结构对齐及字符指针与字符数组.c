#include<stdio.h>
#pragma pack(4)
typedef struct node {
	char f;
	short a;
	char b;
	int e;  //short e; //若为short则结果为8
} node;

int main(int argc, char* argv[]) {
	node n;
	node* p = &n;
	n.f = 'a';
	n.a = 1000;
	printf("%d\n", sizeof(n)); //12，偶数地址开始读取
	printf("%c\n", n); //结构名也是结构的首地址，但不允许类型转换
	printf("************************************\n");
	char* ch;
	char arr[256];
	ch = arr; //ch未初始化时不允许赋值
	ch[0] = 'h';
	ch[1] = 'i';
	ch[2] = '\0';
	printf("%s\n", ch);

	int* ptr = &arr; //数组名取地址还是首地址，即arr == &arr == &(arr[0])
	printf("arr:%p &arr:%p &&arr:%p", arr, ptr, &ptr);
	return 0;
}