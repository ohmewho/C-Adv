#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * next;
} aNode;

typedef aNode * ptrNode; 

typedef struct {
	ptrNode Head, Tail;
} List;

void add(List *);
void printList(List);

int main(){
	ptrNode pHead;
	
	pHead = NULL;
	
	List L;
	L.Head = L.Tail = pHead;
	
	
	add(&L);
//	printf("L.head->data = %d\n", L.Head->data);
	printList(L);
	return 0;
}

void add(List *pList){
	int num;
	scanf("%d", &num);	
	
	while(num != -1){
		ptrNode p = (ptrNode)malloc(sizeof(aNode));
		p->data = num;
		p->next = pList->Head;
		pList->Head = p;
		scanf("%d", &num);
	}
}

void printList(List L){
	int first = 1;
	ptrNode p = L.Head;
	while(p != L.Tail){
		if( first ) first = 0;
		else printf(" ");
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}
