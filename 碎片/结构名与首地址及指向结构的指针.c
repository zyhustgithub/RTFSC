#include <stdio.h>
#include<stdlib.h>
typedef struct node {
	int* elem;
	int length;
	int listsize;
} node;

int main()
{
	int* mem;
	mem = (int*)malloc(10 * sizeof(int));
	int* memptr = mem;
	mem[0] = 'Q';

	node nodedata = {mem, 0, 10};
	node* nodeptr;
	nodeptr = &nodedata;

	printf("sizeof(node):%d\n", sizeof(node));

	printf("&nodedata:%p\n", &nodedata); //结构名既是结构的首地址<打印函数是打印该地址的值，要打印该地址本身要用&取地址符>
	//fflush(stdout);
	printf("&nodedata.elem:%p\n",  &nodedata.elem); //结构首地址既是第一个元素的首地址
	printf("&nodeptr->elem:%p\n",  &nodeptr->elem); 
	printf("&mem:%p\n", &mem); //mem、memptr、nodedata、nodedata.elem、nodeptr->elem地址的值均为10个int数组的首地址
	printf("&memptr:%p\n", &memptr ); //nodedata、nodedata.elem、nodeptr->elem自身的地址均为结构首地址，是一样的。但是mem、memptr自身的地址是不一样的


	printf("%c\n", *mem);

	return 0;
}