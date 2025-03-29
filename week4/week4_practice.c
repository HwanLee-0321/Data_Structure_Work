#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// // 프로그램 4.1
// // 정수 배열 스택 프로그램
// #define MAX_STACK_SIZE 100
// typedef int element;
// element stack[MAX_STACK_SIZE];
// int top = -1;

// // 공백 상태 검출 함수
// int is_empty(){ return (top == -1); }

// // 포화 상태 검출 함수
// int is_full(){ return (top == (MAX_STACK_SIZE - 1)); }

// // 삽입 함수
// void push(element item){
//     if (is_full()){
//         fprintf(stderr, "스택 포화 에러\n");
//     } else stack[++top] = item;
// }

// // 삭제 함수
// element pop(){
//     if (is_empty()){
//         fprintf(stderr," 스택 공백 에러\n");
//     } else return stack[top--];
// }

// // 피크 함수
// element peek(){
//     if (is_empty()){
//         fprintf(stderr, "스택 공백 에러\n");
//         exit(1);
//     } else return stack[top--];
// }

// // 메인 함수
// int main(){
//     push(1);
//     push(2);
//     push(3);
//     printf("%d\n", pop());
//     printf("%d\n", pop());
//     printf("%d\n", pop());
//     return 0;
// }

// // 프로그램 4.2
// // 구조체 배열 스택 프로그램
// #define MAX_STACK_SIZE 100
// #define MAX_STRING 100
// typedef struct {
//     int student_no;
//     char name[MAX_STRING], address[MAX_STRING];
// } element;

// element stack[MAX_STACK_SIZE];
// int top = -1;

// // 공백 상태 검출 함수
// int is_empty(){ return (top == -1); }

// // 포화 상태 검출 함수
// int is_full(){ return (top == (MAX_STACK_SIZE - 1)); }

// // 삽입 함수
// void push(element item){
//     if (is_full()){
//         fprintf(stderr, "스택 포화 에러\n");
//     } else stack[++top] = item;
// }

// // 삭제 함수
// element pop(){
//     if (is_empty()){
//         fprintf(stderr," 스택 공백 에러\n");
//     } else return stack[top--];
// }

// // 피크 함수
// element peek(){
//     if (is_empty()){
//         fprintf(stderr, "스택 공백 에러\n");
//         exit(1);
//     } else return stack[top--];
// }

// int main(){
//     element ie = {20190001,
//                   "Hong",
//                   "Seoul" };
//     element oe;
//     push(ie);
//     oe = pop();
    
//     printf("학번: %d\n", oe.student_no);
//     printf("이름: %s\n", oe.name);
//     printf("주소: %s\n", oe.address);
//     return 0;
// }

// // 프로그램 4.3
// // 일반적인 배열 스택 프로그램
// #define MAX_STACK_SIZE 100

// typedef int element;
// typedef struct {
//     element data[MAX_STACK_SIZE];
//     int top;
// } StackType;

// // 스택 초기화 함수
// void init_stack(StackType *s){ s->top = -1; }

// // 공백 상태 검출 함수
// int is_empty(StackType *s){ return (s->top == -1); }

// // 포화 상태 검출 함수
// int is_full(StackType *s){ return (s->top == (MAX_STACK_SIZE - 1)); }

// // 삽입함수
// void push(StackType *s, element item){
//     if (is_full(s)){
//         fprintf(stderr, "스택 포화 에러\n");
//         return;
//     } else s->data[++(s->top)] = item;
// }

// // 삭제함수
// element pop(StackType *s){
//     if (is_empty(s)){
//         fprintf(stderr, "스택 공백 에러\n");
//     } else return s->data[(s->top)--];
// }

// // 피크함수
// element peek(StackType *s){
//     if (is_empty(s)){
//         fprintf(stderr, "스택 공백 에러\n");
//         exit(1);
//     } else return s->data[s->top];
// }

// int main(){
//     StackType s;

//     init_stack(&s);
//     push(&s, 1);
//     push(&s, 2);
//     push(&s, 3);
//     printf("%d\n", pop(&s));
//     printf("%d\n", pop(&s));
//     printf("%d\n", pop(&s));
// }

// 프로그램 4.4
// // 동적 스택 프로그램
// #define MAX_STACK_SIZE 100

// typedef int element;
// typedef struct {
//     element data[MAX_STACK_SIZE];
//     int top;
// } StackType;

// // 스택 초기화 함수
// void init_stack(StackType *s){ s->top = -1; }

// // 공백 상태 검출 함수
// int is_empty(StackType *s){ return (s->top == -1); }

// // 포화 상태 검출 함수
// int is_full(StackType *s){ return (s->top == (MAX_STACK_SIZE - 1)); }

// // 삽입함수
// void push(StackType *s, element item){
//     if (is_full(s)){
//         fprintf(stderr, "스택 포화 에러\n");
//         return;
//     } else s->data[++(s->top)] = item;
// }

// // 삭제함수
// element pop(StackType *s){
//     if (is_empty(s)){
//         fprintf(stderr, "스택 공백 에러\n");
//     } else return s->data[(s->top)--];
// }

// // 피크함수
// element peek(StackType *s){
//     if (is_empty(s)){
//         fprintf(stderr, "스택 공백 에러\n");
//         exit(1);
//     } else return s->data[s->top];
// }

// int main(){
//     StackType *s;
//     s = (StackType *)malloc(sizeof(StackType));
//     init_stack(&s);
//     push(&s, 1);
//     push(&s, 2);
//     push(&s, 3);
//     printf("%d\n", pop(&s));
//     printf("%d\n", pop(&s));
//     printf("%d\n", pop(&s));
//     free(s);
// }


// // 프로그램 4.5
// // 동적 스택 프로그램
// #define MAX_STACK_SIZE 100

// typedef int element;
// typedef struct {
//     element *data;
//     int capacity;
//     int top;
// } StackType;

// // 스택 생성 함수
// void init_stack(StackType *s){
//     s->top = -1;
//     s->capacity = 1;
//     s->data= (element *)malloc(s->capacity * sizeof(element));
// }

// // 공백 상태 검출 함수
// int is_empty(StackType *s){ return (s->top == -1); }

// // 포화 상태 검출 함수
// int is_full(StackType *s){ return (s->top == (s->capacity -1)); }

// // 삽입함수
// void push(StackType *s, element item){
//     if (is_full(s)){
//         s->capacity *= 2;
//         s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
//     } 
//     s->data[++(s->top)] = item;
// }

// // 삭제함수
// element pop(StackType *s){
//     if (is_empty(s)){
//         fprintf(stderr, "스택 공백 에러\n");
//     } else return s->data[(s->top)--];
// }

// int main(){
//     StackType s;
//     init_stack(&s);
//     push(&s, 1);
//     push(&s, 2);
//     push(&s, 3);
//     printf("%d\n", pop(&s));
//     printf("%d\n", pop(&s));
//     printf("%d\n", pop(&s));
//     free(s.data);
// }

// // 프로그램 4.6
// // 괄호 검사 프로그램
// typedef int element;
// typedef struct {
//     element *data;
//     int capacity;
//     int top;
// } StackType;

// // 스택 생성 함수
// void init_stack(StackType *s) {
//     s->top = -1;
//     s->capacity = 1;
//     s->data = (element *)malloc(s->capacity * sizeof(element));
// }

// // 공백 상태 검출 함수
// int is_empty(StackType *s) {
//     return (s->top == -1);
// }

// // 포화 상태 검출 함수
// int is_full(StackType *s) {
//     return (s->top == (s->capacity - 1));
// }

// // 삽입 함수
// void push(StackType *s, element item) {
//     if (is_full(s)) {
//         s->capacity *= 2;
//         s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
//     }
//     s->data[++(s->top)] = item;
// }

// // 삭제 함수
// element pop(StackType *s) {
//     if (is_empty(s)) {
//         fprintf(stderr, "스택 공백 에러\n");
//         exit(1);  // 함수가 반환형이 있으므로 반드시 종료 또는 유효값 반환 필요
//     }
//     return s->data[(s->top)--];
// }

// // 괄호 검사 함수
// int check_matching(const char *in) {
//     StackType s;
//     init_stack(&s);

//     for (int i = 0; in[i] != '\0'; i++) {
//         char ch = in[i];
//         if (ch == '(' || ch == '[' || ch == '{') {
//             push(&s, ch);
//         } else if (ch == ')' || ch == ']' || ch == '}') {
//             if (is_empty(&s)) {
//                 free(s.data);
//                 return 0;
//             }
//             char open_ch = pop(&s);
//             if ((open_ch == '(' && ch != ')') ||
//                 (open_ch == '[' && ch != ']') ||
//                 (open_ch == '{' && ch != '}')) {
//                 free(s.data);
//                 return 0;
//             }
//         }
//     }

//     int result = is_empty(&s);
//     free(s.data);
//     return result;
// }

// int main() {
//     const char *p = "{ A[(i+1)]=0; }";
//     if (check_matching(p) == 1)
//         printf("%s 괄호검사성공\n", p);
//     else
//         printf("%s 괄호검사실패\n", p);
//     return 0;
// }

