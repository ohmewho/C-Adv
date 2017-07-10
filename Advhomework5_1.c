#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

void printNode(List); 

int main()
{
    int num, i;
    List L, p;
 //   printf("%d\n", sizeof(int));

    scanf("%d", &num);
    L = NULL;
    while ( num != -1 ) {
        p = (List)malloc(sizeof(struct Node));
        p->Data = num;
        p->Next = L;  L = p;
        scanf("%d", &num);
        
    }
    
    printNode(L);
//    printf("%d\n", FactorialSum(L));

    return 0;
}

/* 你的代码将被嵌在这里 */

void printNode(List l){
	List temp = l;
	int tempdata, first = 1;
	while( temp ) {
		if( first ) first = 0;
		else printf(" ");
		printf("%d", temp->Data);
		temp = temp->Next;
	}
}
