# LinkedList.c Explained

## ✨ 개요
`LinkedList.c`는 단순 연결 리스트의 그림 구조와 함수 구현이 가장 가장 종합적으로 구성된 구조입니다.
- 노드 부착은 매니아 목록과 같이 head 나 그 이전의 노드(pre)를 가지고 처리

---

## ▶️ 구조 개요
```c
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;
```
- element: `int` 형

---

## 함수 내용

### 1. `insert_first(ListNode *head, int value)`
- 앞에 값 추가
- malloc 통해 새 노드 만들고 head 가능

### 2. `insert(ListNode *head, ListNode *pre, element value)`
- pre 노드 뒤에 값 추가
- 중간 뒤에 값을 삽입하기 위해 link 변경

### 3. `delete_first(ListNode *head)`
- 노드 가장 앞 삭제
- head 노드 제거 후, free()

### 4. `delete(ListNode *head, ListNode *pre)`
- pre 노드 뒤 사이 노드 삭제
- free() 해제, pre 노드의 link 초과

### 5. `print_list(ListNode *head)`
- 노드 목록 순차적 표시

---

## 예제 사용
```c
ListNode *head = NULL;
head = insert_first(head, 10);
head = insert_first(head, 20);
head = insert_first(head, 30);
print_list(head);  // 30 -> 20 -> 10 -> NULL
head = delete_first(head);
print_list(head);  // 20 -> 10 -> NULL
```

---

## 주의 점
- `insert`, `delete` 함수는 **pre노드 가지고 해석**
- `NULL` 처리 위해 상황 검사 필요
- 변수 이름, 함수 명이 규칙적으로 잘 지정됨

---

## 개인적 평가
- 다음 연결 리스트 함수들을 하나의 파일에 종합하고 있어 조회와 결과 해석에 도움
- linked list 구조의 기본과 결정치 가능성을 유지

