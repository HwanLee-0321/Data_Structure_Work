# Lap1.c Explained

## ✨ 개요
`Lap1.c`는 단순 연결 리스트(Singly Linked List)를 구현한 것으로, 데이터 규정과 추가, 출력 기능을 포함합니다.

---

## ▶️ 실행 순서 (main)
1. `ListNode *head = NULL;`
2. `data.name` 바꿀 때마다 `insert_first()` 호출
3. 리스트 표시 (`print_list()`)

---

## 파일 구조
```c
typedef struct {
    char name[100];
} element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;
```
- 전형: `element` (문자열 name)
- 단순 연결 리스트의 개갛자 `ListNode`

---

## 함수 내용

### 1. `insert_first(ListNode *head, element value)`
- 마우배를 통해 새 노드를 만들고, 기존 head 앞에 삽입
- 새 노드는 입력 값 `value`를 가진다.
- 출력: 가장 각자적 노드인 새 head 노드

### 2. `print_list(ListNode *head)`
- 리스트 노드를 순차적으로 출력 (name -> name -> NULL)
- 해당 함수 메인에서 `print_lsit()`가 잘못 적용되어 있음 (**매 호출을 `print_list()`로 교체 필요**)

---

## 개인적 해석
- 패턴:
  1. "BANANA" -> "KIWI" -> "APPLE" -> NULL
- 배열과 다르게, 값이 추가될 때 가장 앞에 삽입되는 구조
- 개격과 최강성: **O(1)** insert at front

---

## 그룹필요 점
- `insert_first()`는 노드 개체를 heap에 만들고, 다음으로 head 값을 변경
- `print_lsit()`는 그대로 실행시 카운팅 오류 발생 (compile OK, runtime ERROR)

---

## 권장
- 간단한 구조로 리스트의 가장 기\uubcf8 조직 결과와 같은 구조 유용
- `free()` 가 없어 메뉴 행사 후 메뉴마다 메르리 문제 발생 가능
- 개인적으로 그룹 구현 등에 중요

