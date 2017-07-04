#include <stdio.h>
int N = 10;

typedef struct {
    char name[20];
    int score[3];
} Student;
 
//    输入一个学生的数据
Student* student_input(Student *pStudent);
//    输出一个学生的数据，包括平均成绩
void student_print(const Student *pStudent);
//    计算一个学生的平均成绩
double student_average(const Student *pStudent);    
//    获得学生的一个成绩
int student_get_score(const Student *pStudent, int index);


int main(int argc, char* argv[]){
	int iter, min[3], max[3], imin, imax, isum;
	int sum[3] = {0};
	Student pStu[N];
	
	for(iter = 0; iter < N; iter++){
		student_input(&pStu[iter]);
	}
	
	for(iter = 0; iter < 3; iter++){
		min[iter] = student_get_score(&pStu[0], iter);
	}
	
	for(iter = 0; iter < 3; iter++){
		max[iter] = student_get_score(&pStu[0], iter);
	}
	
	printf("%s\t%s\t%s\t%s\t%s\t%s\n", "no", "name","score1", "score2", "score3", "average");
	for(iter = 0; iter < N; iter++){
		for(imax = 0; imax < 3; imax++){
			if(max[imax] < student_get_score(&pStu[iter], imax)) max[imax] = student_get_score(&pStu[iter], imax);
		}
		
		for(imin = 0; imin < 3; imin++){
			if(min[imin] > student_get_score(&pStu[iter], imin)) min[imin] = student_get_score(&pStu[iter], imin);
		}
		
		for(isum = 0; isum < 3; isum++){
			sum[isum] += student_get_score(&pStu[iter], isum);
		}
		
		printf("%d", iter + 1);
		student_print(&pStu[iter]);
	}
	
	printf("\t%-8s%.1f\t%.1f\t%.1f\n", "average", sum[0] * 1.0 / N, sum[1] * 1.0 / N, sum[2] * 1.0 / N);
	printf("\t%s\t%d\t%d\t%d\n", "min", min[0], min[1], min[2]);
	printf("\t%s\t%d\t%d\t%d\n", "max", max[0], max[1], max[2]);
	
	return 0;
}

Student* student_input(Student *pStudent){
	
	scanf("%s", &pStudent->name);
	scanf("%d", &pStudent->score[0]);
	scanf("%d", &pStudent->score[1]);
	scanf("%d", &pStudent->score[2]);
	
	return pStudent;
}

void student_print(const Student *pStudent){
	printf("\t%s\t%d\t%d\t%d\t", pStudent->name, student_get_score(pStudent, 0), student_get_score(pStudent, 1), student_get_score(pStudent, 2));
	if(student_average(pStudent) - (int)student_average(pStudent) == 0) printf("%d\n", (int)student_average(pStudent));//判断平均成绩是否为整数 
	else printf("%.5f\n", student_average(pStudent));
}

double student_average(const Student *pStudent){
	double avg;
	avg = (student_get_score(pStudent, 0) + student_get_score(pStudent, 1) + student_get_score(pStudent, 2)) * 1.0 / 3;
	return avg;
}

int student_get_score(const Student *pStudent, int index){
	return pStudent->score[index];
}
