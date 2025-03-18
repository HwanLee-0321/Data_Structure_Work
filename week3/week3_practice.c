// 아래 헤더파일은 그대로 두기
#include <stdio.h>

// 프로그램 3.1
// structure.c
// 학생들의 성적 관리 시스템

// typedef stuct sutendTag {
//     char name[10];
//     int age;
//     double gpa;
// } student;

// int main(void){
//     student a = {"kim", 20, 4.3};
//     studnet b = {"park", 21, 4.2};
//     return 0;
// }

// 프로그램 3.2
// polynomial.c
// 다항식 덧셈 프로그램 #1

#define MAX(a,b) (((a)>(b)?(a):(b)))
#define MAX_DEGREE 101
typedef struct{
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

// C = A+B 여기서 A와 B는 다항식이다. 구조체가 반환된다.
polynomial poly_add1(polynomial A, polynomial B){
    polynomial C;
    int Apos = 0, Bpos = 0, Cpos 0;
    
}
