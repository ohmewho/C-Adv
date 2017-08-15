#include <stdio.h>
#define MAX 51

typedef struct arn {
    char sign;
    int length;
    int nums[MAX];
} RealNumber;

void swap(int *m, int *n){
	int temp = *m;
	*m = *n;
	*n = temp;
}

RealNumber chartoRN(char * str){
	RealNumber rtn;
	int iter = 0, start, end;
	while(str[iter++] == ' ');
	iter--;
	
	if(str[iter] == '-') {
		rtn.sign = str[iter];
		start = iter + 1;
	}
	else {
		rtn.sign = '+';
		start = iter;
	}
	end = start;
	printf("start = %d\n", start);
	while(str[end++]){
		rtn.nums[end - 1] = str[end - 1] - '0';
	}
	end--;
	printf("end = %d\n", end);
	rtn.length = end;
	
	return rtn;
}



void printRN(RealNumber rn){
	int iter;
	if(rn.sign == '-') printf("%c", rn.sign);
	for(iter = 0; iter < rn.length; iter++){
		printf("%d", rn.nums[iter]);
	}
	printf("\n");
}

void reverseRN(RealNumber rn){
	int iter, temp;
	for(iter = 0; iter < rn.length / 2; iter++){
		swap(&rn.nums[iter], &rn.nums[rn.length - 1 - iter]);
	}
	printRN(rn);
}

int main(){
	
    char num1[MAX], num2[MAX];
    RealNumber rn1, rn2;
    scanf("%s %s", num1, num2);
    //scanf("%s", num2);
    rn1 = chartoRN(num1);
    rn2 = chartoRN(num2);

    printRN(rn1); 
    reverseRN(rn1);
    printRN(rn1);
    printRN(rn2); 


    return 0;
}
