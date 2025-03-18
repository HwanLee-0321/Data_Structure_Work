// 아래 헤더파일은 그대로 두기
#include <stdio.h>
#include <stdlib.h>

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

// #define MAX(a, b) (((a) > (b)) ? (a) : (b))
// #define MAX_DEGREE 101

// typedef struct {
//     int degree;
//     float coef[MAX_DEGREE];
// } polynomial;

// polynomial poly_add1(polynomial A, polynomial B) {
//     polynomial C = { MAX(A.degree, B.degree), {0} };

//     for (int i = 0; i <= C.degree; i++)
//         C.coef[i] = A.coef[i] + B.coef[i];

//     while (C.degree > 0 && C.coef[C.degree] == 0)
//         C.degree--;

//     return C;
// }

// void print_poly(polynomial p) {
//     for (int i = p.degree; i >= 0; i--) 
//         if (p.coef[i] != 0) 
//             printf(i == p.degree ? "%.1fx^%d" : " + %.1fx^%d", p.coef[i], i);
//     printf("\n");
// }

// int main() {
//     polynomial a = {5, {10, 10, 10, 10, 10, 10}};
//     polynomial b = {4, {1, 1, 1, 1, 1}};
    
//     printf("A: "); print_poly(a);
//     printf("B: "); print_poly(b);
//     printf("-------------------------\n");
//     printf("C (A + B): "); print_poly(poly_add1(a, b));

//     return 0;
// }
