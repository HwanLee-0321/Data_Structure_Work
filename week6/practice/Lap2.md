# Lap2.c Explained

## ✨ 개요
`Lap2.c`는 정수 형 데이터를 가지는 단순 연결 리스트(Singly Linked List)의 삽입, 표시, 검색 기능을 구현한 파일입니다.

---

## ▶️ 실행 순서
1. `insert_first()` 호출으로 값 10, 20, 30 순차적으로 삽입
2. 링크 가지고 노드 표시 (`print_list`)
3. `search_list()` 호출으로 값 30 검색
4. 결과 연결으로 자동 출력

---

## 구조
```c
typedef int element;
typedef struct {
    element data;
    struct ListNode *link;
} ListNode;
```
- 값은 `int`로 지정하고 구조는 개갛자 단위

---

## 함수 내용

### 1. `insert_first(ListNode *head, element value)`
- 각 호출시 개갛자 삽입
- 값을 `data`에 대입, 그 다음 노드는 head가 가캵
- 새 head 노드 반환

### 2. `print_list(ListNode *head)`
- 노드를 순차적으로 출력 (10 -> 20 -> ... -> NULL)

### 3. `search_list(ListNode *head, element x)`
- 지정한 값 `x`가 노드 내에 있는지 검색
- 일치하는 노드 반환, 없으면 `NULL`

---

## 예제 실행 결과
```c
head = insert_first(head, 10);  // 10
head = insert_first(head, 20);  // 20 -> 10
head = insert_first(head, 30);  // 30 -> 20 -> 10
```
- `search_list(head, 30)`는 성공 검색 -> 결과 표시

---

## 주의 점
- `search_list`는 처음 개가지가 일치할 경우만 검색 성공
- 새 노드 삽입 순서가 매우 중요
- `free()` 개체 면에서 노드 제거는 구현되지 않음

---

## 개인적 갤럭시
- 단순 연결 리스트의 기준적 기능 구현 예제
- 추가/ 검색 기능에 중점
- 개갛자를 통해 특정 값을 직관적으로 찾을 수 있는 구조

