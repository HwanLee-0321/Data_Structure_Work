// 아래 헤더파일은 그대로 두기
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

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

// 프로그램 3.3
// polynomial2.c
// 다항식 덧셈 프로그램 2

// #define MAX_TERM 101

// typedef struct {
//     float coef;
//     int expon;
// } polynomial;

// polynomial terms[MAX_TERM] = { {8,3},{7,1},{1,0},{10,3},{3,2},{1,0} };
// int avail = 6;

// // 두 개의 정수를 비교
// char compare(int a, int b) {
//     if (a > b) return '>';
//     else if (a == b) return '=';
//     else return '<';
// }

// // 새로운 항을 다항식에 추가
// void attach(float coef, int expon) {
//     if (avail >= MAX_TERM) {  // 조건 수정 (>=)
//         fprintf(stderr, "항의 개수가 너무 많음\n");
//         exit(1);
//     }
//     terms[avail].coef = coef;
//     terms[avail].expon = expon;
//     avail++;
// }

// // C = A + B
// void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce) {
//     float tempcoef;
//     *Cs = avail;

//     while (As <= Ae && Bs <= Be) {
//         switch (compare(terms[As].expon, terms[Bs].expon)) {
//             case '>':
//                 attach(terms[As].coef, terms[As].expon);
//                 As++;
//                 break;
//             case '=':
//                 tempcoef = terms[As].coef + terms[Bs].coef;
//                 if (tempcoef) attach(tempcoef, terms[As].expon);
//                 As++;
//                 Bs++;
//                 break;
//             case '<':
//                 attach(terms[Bs].coef, terms[Bs].expon);
//                 Bs++;
//                 break;
//         }
//     }

//     // A의 나머지 항들을 추가
//     for (; As <= Ae; As++)
//         attach(terms[As].coef, terms[As].expon); // 수정

//     // B의 나머지 항들을 추가
//     for (; Bs <= Be; Bs++)
//         attach(terms[Bs].coef, terms[Bs].expon);

//     *Ce = avail - 1;
// }

// // 다항식 출력 함수
// void print_poly(int s, int e) {
//     for (int i = s; i < e; i++)
//         printf("%.1fx^%d + ", terms[i].coef, terms[i].expon);
//     printf("%.1fx^%d\n", terms[e].coef, terms[e].expon);
// }

// int main() {
//     int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;

//     printf("다항식 A: ");
//     print_poly(As, Ae);

//     printf("다항식 B: ");
//     print_poly(Bs, Be);

//     poly_add2(As, Ae, Bs, Be, &Cs, &Ce);

//     printf("-------------------------------------------------------\n");
//     printf("다항식 C (A + B): ");
//     print_poly(Cs, Ce);

//     return 0;
// }

// 프로그램 3.4
// matrix.c
// 행렬 전치 프로그램 #1

// #define ROWS 3
// #define COLS 3
// // 행렬 전치 함수
// void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS]){
//     for (int r = 0; r < ROWS; r++){
//         for (int c = 0; c < COLS; c++){
//             B[c][r] = A[r][c];
//         }
//     }
// }
// void matrix_print(int A[ROWS][COLS]){
//     printf("------------------\n");
//     for (int r = 0; r<ROWS; r++){
//         for (int c = 0; c<COLS; c++){
//             printf("%d ", A[r][c]);
//         }
//         printf("\n");
//     }
//     printf("------------------\n");
// }

// int main(){
//     int array1[ROWS][COLS] = {{2,3,0},
//                               {8,9,1},
//                               {7,0,5}};
//     int array2[ROWS][COLS];

//     matrix_transpose(array1, array2);
//     matrix_print(array1);
//     matrix_print(array2);
//     return 0;
// }

// #define MAX_TERMS 100
// typedef struct {
//     int row, col, value;
// } element;

// typedef struct SpareMatrix {
//     element data[MAX_TERMS];
//     int rows, cols, terms;
// } SpareMatrix;

// SpareMatrix matrix_trnasepose2(SpareMatrix a){
//     SpareMatrix b;
//     int bindex;
//     b.rows = a.cols;
//     b.cols = a.rows;
//     b.terms = a.terms;

//     if (a.terms > 0){
//         bindex = 0;
//         for (int c = 0; c < a.cols; c++){
//             for (int i = 0; i < a.terms; i++){
//                 if (a.data[i].col == c){
//                     b.data[bindex].row = a.data[i].col;
//                     b.data[bindex].col = a.data[i].row;
//                     b.data[bindex].value = a.data[i].value;
//                     bindex ++;
//                 }
//             }
//         }
//     }
//     return b;
// }

// void matrix_print(SpareMatrix a){
//     printf("------------------------------------\n");
//     for (int i = 0; i < a.terms; i++){
//         printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
//     }
//     printf("------------------------------------\n");
// }

// int main(){
//     SpareMatrix m = {
//         {{0,3,7}, {1,0,9}, {1,5,8}, {3,0,6}, {3,1,5}, {4,5,1},{5,2,2}},
//         6,
//         6,
//         7
//     };
//     SpareMatrix result;

//     result = matrix_trnasepose2(m);
//     matrix_print(result);
//     return 0;
// }

// 프로그램 3.6
// swap.c
// 포인터를 함수의 매개변수로 사용하는 프로그램

// void swap(int *px, int *py){
//     int tmp;
//     tmp = *px;
//     *px = *py;
//     *py = tmp;
// }

// int main(){
//     int a=1, b=2;
//     printf("swap을 호출하기 전: a=%d, b=%d\n", a,b);
//     swap(&a, &b);
//     printf("swap을 호출한 다음: a=%d, b=%d\n", a,b);
//     return 0;
// }

// 프로그램 3.7
// array1.c
// 배열을 함수의 매개변수로 사용하는 프로그램

// #define SIZE 6

// // 정수를 입력받는 함수
// void get_integers(int *list) {
//     printf("6: ");
//     for (int i = 0; i < SIZE; ++i) {
//         scanf("%d", list + i);
//     }
// }

// // 배열의 합을 계산하는 함수
// int cal_sum(const int *list, int size) {

//     int sum = 0;
//     for (int i = 0; i < size; ++i) {
//         sum += *(list + i);
//     }
//     return sum;
// }

// // 메인 함수
// int main() {
//     int list[SIZE];

//     get_integers(list);
//     printf("합 = %d\n", cal_sum(list, SIZE));

//     return 0;
// }

// 프로그램 3.8
// malloc.c
// 동적 메모리 할당의 예   

// MALLOC.C: malloc을 이용하여 정수 10을 저장할 수 있는 동적 메모리를
// // 할당하고 free를 이욯여 메모리를 반납한다.

// #define SIZE 10

// int main(){
//     int *p;

//     p = (int *)malloc(SIZE * sizeof(int));
//     if (p == NULL){
//         fprintf(stderr, "메모리가 부족해서 할달할 수 없습니다.\n");
//         exit(1);
//     }
//     for (int i = 0; i < SIZE; i++){
//         p[i] = i;
//     }
//     for (int i = 0; i < SIZE; i++){
//         printf("%d ", p[i]);
//     }
//     free(p);
//     return 0;
// }

// 프로그램 3.9
// malloc.c
// 동적 메모리 할당 사용 예제

// typedef struct studentTag{
//     char name[10];
//     int age;
//     double gpa;
// } student;

// int main(){
//     student *s;

//     s = (student *)malloc(sizeof(student));
//     if (s==NULL){
//         fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
//         exit(1);
//     }

//     strcpy(s->name, "Park");
//     s->age = 20;
//     free(s);
//     return 0;
// }