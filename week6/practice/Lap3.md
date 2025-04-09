# Lap3.c Explained

## ✨ 개요
`Lap3.c`는 정수 형 단순 연결 리스트 2개를 합치는 **concat_list** 함수를 포함한 구조입니다.

---

## ▶️ 실행 순서
1. `head1`, `head2` 노드 삽입 (insert_first)
2. 각 리스트 표시 (print_list)
3. `concat_list(head1, head2)` 호출
4. 연결 리스트 결과 표시

---

## 구조
```c
typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;
```

---

## 함수 내용

### 1. `insert_first(ListNode *head, element value)`
- 개갛자에 삽입 해석

### 2. `print_list(ListNode *head)`
- 순차적 노드 출력

### 3. `concat_list(ListNode *head1, ListNode *head2)`
- 두 리스트 개체를 합치는 함수
- 호출 이번:
```c
if (head1 == NULL) return head2;
else if (head2 == NULL) return head1;
else {
    ListNode *p = head1;
    while (p->link != NULL)
        p = p->link;
    p->link = head2;
    return head1;
}
```
- head1 마지막 노드를 찾은 후, head2 를 그 다음으로 연결

---

## 예제 실행 결과
```c
head1: 30 -> 20 -> 10 -> NULL
head2: 50 -> 40 -> NULL
total: 30 -> 20 -> 10 -> 50 -> 40 -> NULL
```

---

## 주의 점
- 노드를 합치는 것이며, 사이에 생성이 보다 이동에 중점
- head1이 NULL일 경우, head2 가 구조의 기준이 됨

---

## 개인적 권장
- 간단한 linked list 합치 구현
- 다음 건에 걸려 연결하는 간단한 함수로, 리스트 노드 삽입/ 합치/ 표시 관련 기능 확장에 중요