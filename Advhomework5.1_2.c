#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * next;
} aNode;

typedef aNode * ptrNode; 

typedef struct {
	ptrNode Head;
	ptrNode Tail;
} List;

void addtoHead(List *);
void printList(List);

void addtoTail (List *);

int main(){
	ptrNode pHead;
	
	pHead = NULL;
	
	List L;
	L.Head = L.Tail = pHead;
	
	
	addtoHead(&L);
//	printf("L.head->data = %d\n", L.Head->data);
	printList(L);
	printList(L);
	addtoTail (&L);
	printList(L);
	return 0;
}

void addtoHead(List *pList){
	int num;
	scanf("%d", &num);	
	
	while(num != -1){
		ptrNode p = (ptrNode)malloc(sizeof(aNode));
		p->data = num;
		p->next = pList->Head;
		if(!pList->Tail) pList->Tail = p;
		pList->Head = p;
		scanf("%d", &num);
	}
}

void printList(List L){
	int first = 1;
	ptrNode p = L.Head;
	while(p){
		if( first ) first = 0;
		else printf(" ");
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}

void addtoTail (List * pList){
	int num;
	scanf("%d", &num);
	ptrNode t = pList->Tail;	
	
	while(num != -1){
		printf("I am here in %s.\n", __func__);
		ptrNode p = (ptrNode)malloc(sizeof(aNode));
		
		p->data = num;
		p->next = NULL;
		if( pList->Head == NULL) {
			pList->Head = p;
			pList->Tail = p;
		}
		else {
			pList->Tail->next = p;
			pList->Tail = p;
		}
		
		scanf("%d", &num);
	}
	printf("Successfully done!\n");
}
