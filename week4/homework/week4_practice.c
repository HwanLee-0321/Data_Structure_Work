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

// // 프로그램 4.7
// // 후위표기식 계산
// #define MAX_STACK_SIZE 100

// typedef char element;
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

// // 후위 표기 수식 계산 함수
// int eval(char exp[]){
//     int op1, op2, value, i = 0;
//     int len = strlen(exp);
//     char ch;
//     StackType s;

//     init_stack(&s);
//     for (i=0;i<len;i++){
//         ch = exp[i];
//         if (ch != '+' && ch !='-' && ch != '*' && ch != '/' ){
//             value = ch - '0';
//             push(&s, value);
//         } else {
//             op2 = pop(&s);
//             op1 = pop(&s);
//             switch (ch)
//             {
//             case '+': push(&s, op1 + op2); break;
//             case '-': push(&s, op1 - op2); break;
//             case '*': push(&s, op1 * op2); break;
//             case '/': push(&s, op1 / op2); break;
//             }
//         }
//     }
//     return pop(&s);
// }

// int main(){
//     int result;
//     printf("후위표기식은 82/3-32*+\n");
//     result = eval("82/3-32*+");
//     printf("결과값은 %d\n",result);
//     return 0;
// }

// // 프로그램 4.8
// // 중위 표기 수식을 후위 표기 수식으로 변환하는 프로그램
// #define MAX_STACK_SIZE 100

// typedef char element;
// typedef struct {
//     element *data;
//     int capacity;
//     int top;
// } StackType;

// void init_stack(StackType *s) {
//     s->top = -1;
//     s->capacity = 1;
//     s->data = (element *)malloc(s->capacity * sizeof(element));
// }

// int is_empty(StackType *s) {
//     return (s->top == -1);
// }

// int is_full(StackType *s) {
//     return (s->top == (s->capacity - 1));
// }

// void push(StackType *s, element item) {
//     if (is_full(s)) {
//         s->capacity *= 2;
//         s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
//     }
//     s->data[++(s->top)] = item;
// }

// element pop(StackType *s) {
//     if (is_empty(s)) {
//         fprintf(stderr, "스택 공백 에러\n");
//         exit(1);
//     }
//     return s->data[(s->top)--];
// }

// element peek(StackType *s) {
//     if (is_empty(s)) {
//         fprintf(stderr, "스택 공백 에러 (peek)\n");
//         exit(1);
//     }
//     return s->data[s->top];
// }

// int prec(char op) {
//     switch (op) {
//         case '(': case ')': return 0;
//         case '+': case '-': return 1;
//         case '*': case '/': return 2;
//     }
//     return -1;
// }

// void infix_to_postfix(char exp[]) {
//     int i;
//     char ch, top_op;
//     int len = strlen(exp);
//     StackType s;

//     init_stack(&s);
//     for (i = 0; i < len; i++) {
//         ch = exp[i];
//         switch (ch) {
//             case '+': case '-': case '*': case '/':
//                 while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
//                     printf("%c", pop(&s));
//                 push(&s, ch);
//                 break;
//             case '(':
//                 push(&s, ch);
//                 break;
//             case ')':
//                 top_op = pop(&s);
//                 while (top_op != '(') {
//                     printf("%c", top_op);
//                     top_op = pop(&s);
//                 }
//                 break;
//             default:
//                 printf("%c", ch);
//                 break;
//         }
//     }
//     while (!is_empty(&s))
//         printf("%c", pop(&s));
// }

// int main() {
//     char *s = "(2+3)*4+9";
//     printf("중위표시수식: %s\n", s);
//     printf("후위표기수식: ");
//     infix_to_postfix(s);
//     printf("\n");
//     return 0;
// }

// // 프로그램 4.9
// // 미로탐색 프로그램
// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 6

// typedef struct {
//     short r;
//     short c;
// } element;

// typedef struct {
//     element *data;
//     int capacity;
//     int top;
// } StackType;

// void init_stack(StackType *s) {
//     s->top = -1;
//     s->capacity = 1;
//     s->data = (element *)malloc(s->capacity * sizeof(element));
// }

// int is_empty(StackType *s) {
//     return (s->top == -1);
// }

// int is_full(StackType *s) {
//     return (s->top == (s->capacity - 1));
// }

// void push(StackType *s, element item) {
//     if (is_full(s)) {
//         s->capacity *= 2;
//         s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
//     }
//     s->data[++(s->top)] = item;
// }

// element pop(StackType *s) {
//     if (is_empty(s)) {
//         fprintf(stderr, "스택 공백 에러\n");
//         exit(1);
//     }
//     return s->data[(s->top)--];
// }

// element peek(StackType *s) {
//     if (is_empty(s)) {
//         fprintf(stderr, "스택 공백 에러 (peek)\n");
//         exit(1);
//     }
//     return s->data[s->top];
// }

// element here = {1, 0}, entry = {1, 0};

// char maze[MAX_SIZE][MAX_SIZE] = {
//     {'1', '1', '1', '1', '1', '1'},
//     {'e', '0', '1', '0', '0', '1'},
//     {'1', '0', '0', '0', '1', '1'},
//     {'1', '0', '1', '0', '1', '1'},
//     {'1', '0', '1', '0', '0', 'x'},
//     {'1', '1', '1', '1', '1', '1'},
// };

// void push_loc(StackType *s, int r, int c) {
//     if (r < 0 || c < 0 || r >= MAX_SIZE || c >= MAX_SIZE) return;
//     if (maze[r][c] != '1' && maze[r][c] != '.') {
//         element tmp = {r, c};
//         push(s, tmp);
//     }
// }

// void maze_print(char maze[MAX_SIZE][MAX_SIZE]) {
//     printf("\n");
//     for (int r = 0; r < MAX_SIZE; r++) {
//         for (int c = 0; c < MAX_SIZE; c++) {
//             printf("%c", maze[r][c]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     int r, c;
//     StackType s;
//     init_stack(&s);
//     here = entry;

//     while (maze[here.r][here.c] != 'x') {
//         r = here.r;
//         c = here.c;
//         maze[r][c] = '.';
//         maze_print(maze);
//         push_loc(&s, r - 1, c);  // 상
//         push_loc(&s, r + 1, c);  // 하
//         push_loc(&s, r, c - 1);  // 좌
//         push_loc(&s, r, c + 1);  // 우

//         if (is_empty(&s)) {
//             printf("실패\n");
//             return 0;
//         } else {
//             here = pop(&s);
//         }
//     }

//     maze_print(maze);
//     printf("성공\n");
//     return 0;
// }
